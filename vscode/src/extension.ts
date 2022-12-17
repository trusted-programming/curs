import * as vscode from 'vscode';
import { refreshDecorations, acceptSuggestion, ignoreSuggestion, tracedFiles } from './decorator';
import { requestDetectPatterns, requestStopDetectPatterns, requestClearDisplay } from './pattern_detection';
import logger from './logger';
import statusBar from './status_bar';


// this method is called when your extension is activated
// your extension is activated the very first time the command is executed
export function activate(context: vscode.ExtensionContext) {
	logger.init(context);
	logger.log('Starting extension curs...');

	statusBar.init(context);

	// register start profiling option (with one time of baseline profiling)
	context.subscriptions.push(vscode.commands.registerCommand('curs.detect', () => {
		requestDetectPatterns();
	}));

	context.subscriptions.push(vscode.commands.registerCommand('curs.stop', () => {
		requestStopDetectPatterns();
	}));

	// register stop profiling option
	context.subscriptions.push(vscode.commands.registerCommand('curs.clear', () => {
		requestClearDisplay();
	}));


	context.subscriptions.push(vscode.commands.registerTextEditorCommand('curs.accept', 
		acceptSuggestion
	));

	context.subscriptions.push(vscode.commands.registerTextEditorCommand('curs.ignore', 
		ignoreSuggestion
	));

	vscode.workspace.onDidSaveTextDocument((event) => {
		if (!statusBar.isBusy() && tracedFiles.has(event.fileName)) {
			logger.log(`Document ${event.fileName} saved.`);
			requestDetectPatterns(true);
		}
	});

	// register to listen to active editor change events (to refresh decorations)
	vscode.window.onDidChangeActiveTextEditor((event) => {
		if (event) {
			logger.log(`Active document switched to ${event.document.fileName}`);
			refreshDecorations(event.document.fileName);
		}
	});

	logger.log('Extension now started.');
}


// this method is called when your extension is deactivated
export function deactivate() { }
