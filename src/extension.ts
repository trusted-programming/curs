// The module 'vscode' contains the VS Code extensibility API
// Import the module and reference it with the alias vscode in your code below
import * as vscode from 'vscode';
import {commands,window,workspace} from 'vscode';

// this method is called when your extension is activated
// your extension is activated the very first time the command is executed
export function activate(context: vscode.ExtensionContext) {
	// Use the console to output diagnostic information (console.log) and errors (console.error)
	// This line of code will only be executed once when your extension is activated
	console.log('Congratulations, your extension "rust-hero" is now active!');

	// The command has been defined in the package.json file
	// Now provide the implementation of the command with registerCommand
	// The commandId parameter must match the command field in package.json
	let disposableCommands = [
		//check all rust files in current workspace
		commands.registerCommand('extension.rust_hero.workspace', () => {
			if (workspace.workspaceFolders !== undefined) {
				let dirpath = workspace.workspaceFolders[0].uri.path;
				const terminal = window.createTerminal(`rust-hero`);
				terminal.sendText(`rust_hero ${dirpath}`);
			}
		}),
				//check current file in open window
		commands.registerCommand('extension.rust_hero.currentfile', () => {
			if (workspace.workspaceFolders !== undefined) {
				let filepath = window.activeTextEditor?.document.uri.fsPath;
				const terminal = window.createTerminal(`rust-hero`);
				terminal.sendText(`rust_hero ${filepath}`);
			}
		}),
	];

	disposableCommands.forEach(command => {
        context.subscriptions.push(command);
    });
}
