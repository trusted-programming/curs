import * as vscode from 'vscode';
import { remoteCall } from './remote_interface';
import { ProfilingEntry, tracedFiles, removeDecorations } from './decorator';
import statusBar from './status_bar';
import { validateConfiguration, onSaveCoolDown } from './configurations';
import logger from './logger';
import { flushDecorations, clearDecorations } from './decorator';
import { ExecException } from 'child_process';
import { existsSync, readdirSync } from 'fs';
import * as path from 'path';
import { performance } from 'perf_hooks';

let sourceFilePath: string | undefined;
let lastUpdatedTime: number | undefined; // record the last time of update
let grammarFileList: string[] | undefined;

function parseProfilingResultString(document: vscode.TextDocument, profilingResultString: string): ProfilingEntry[] {
    // parse profiling results:
    // expected result format: <func_name>, <start_line>, <start_col>, <end_line>, <end_col>, <trigger_file>, <suggested_action>, <code_snippet>
    // <func_name>, <trigger_file>: string
	// <start_line>, <start_col>, <end_line>, <end_col>: number
    // <suggested_action>: string, which should be the type of action (e.g., replace, add, delete) without double quotation mark (")
	// <code_snippet> should be the code snippet that escape line feed (i.e., use \\n instead of \n) surrounded with double quotation marks (")
	var rows = "";
	profilingResultString.trim().split('\n').filter((row) => {
        const values = row.split(',');
		const startLine = parseInt(values[1]) - 1;
		const signature = document.lineAt(startLine).text;
		const to_warn = (signature.indexOf("unsafe") >= 0 && values[5].indexOf("Safe") >= 0);
		if (to_warn) {
			rows = rows + "\n" + row
		}
	});
	return rows.trim().split('\n').map((row) => {
		logger.log(row);
		const quotationContent = row.endsWith('""') ? "" : row.substring(row.substring(0, row.length-2).lastIndexOf('"')+1, row.length-1).replace('\\n', '\n');
        const values = row.split(',');
		const startLine = parseInt(values[1]) - 1;
		// const startCol = parseInt(values[2]) - 1 ;
		// const endLine = parseInt(values[3]) - 1;
		// const endCol = parseInt(values[4]) - 1;
		const triggerFile = values[5];
		const suggestedAction = values[5];
		const signature = document.lineAt(startLine).text;
		const startCol = signature.indexOf("unsafe");
		const endLine = startLine;
		const endCol = startCol + "unsafe".length;
		return {
			profilingIndex: triggerFile+','+startLine+','+startCol+','+endLine+','+endCol,
			startLine: startLine,
			startCol: startCol,
			endLine: endLine,
			endCol: endCol,
			triggerFile: triggerFile,
			suggestedAction: 'delete',
			suggestedSnippet: quotationContent,
		}
    });
}


export function requestDetectPatterns(eventTriggered: boolean = false) {
	if (statusBar.isBusy()) {
		logger.error('Another task is already running.');
		return;
	}

	// confirm existence of active window
	if (!vscode.window.activeTextEditor) {
		logger.error('Focus not in an active editor window. Please open the file to be profiled and try again.');
		statusBar.endExecution();
		return;
	}
	const document = vscode.window.activeTextEditor.document;

	// validate configuration items
	if (!validateConfiguration()) {
		logger.error('Failed to validate configuration items.');
		statusBar.endExecution();
		return;
	}

	// use cool down to prevent overly frequent on save update request
	if (eventTriggered) {
		if (!onSaveCoolDown) {
			logger.error('Unexpected error.');
			return;
		}
		if (lastUpdatedTime && performance.now() - lastUpdatedTime < onSaveCoolDown) {
			logger.log('Auto update profiling halted due to cool down.');
			return;
		} else {
			lastUpdatedTime = performance.now();	
		}
	}

	sourceFilePath = document.fileName;
	logger.log(`Target source code file: ${sourceFilePath}.`);

	statusBar.startDetection();
	remoteCall(sourceFilePath, receivedDetectPatterns);
}


function receivedDetectPatterns(error: ExecException | null, stdout: string, stderr: string) {
	if (error) {
		statusBar.endExecution();
		logger.error(`Failed to detect patterns for error ${error}: ${stderr}.`);
		return;
	}

	if (!sourceFilePath) {
		statusBar.endExecution();
		logger.error('Unexpected error.');
		return;
	}
	
	statusBar.endExecution();
	logger.log('Finished detection. Parsing results...');
	if (vscode.window.activeTextEditor) {
		const document = vscode.window.activeTextEditor.document;
		const profilingResult = parseProfilingResultString(document, stdout);
		flushDecorations(sourceFilePath, profilingResult);	
	}
}


export function requestClearDisplay() {
	if (tracedFiles.size > 0) {
		logger.log('Clear detection display...');
		clearDecorations();
	}
}


export function requestStopDetectPatterns() {
	if (statusBar.isBusy()) {
		logger.error('Another task is already running.');
		return;
	}

	// confirm existence of active window
	if (!vscode.window.activeTextEditor) {
		logger.error('Focus not in an active editor window.');
		return;
	}
	const document = vscode.window.activeTextEditor.document;

	if (!tracedFiles.has(document.fileName)) {
		logger.error('Pattern detection not active for the current file.');
		return;
	}

	removeDecorations(document.fileName);
}
