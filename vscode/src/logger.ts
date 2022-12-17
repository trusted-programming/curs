import * as vscode from 'vscode';

  
class Logger {
	private readonly outputChannel: vscode.OutputChannel;

    constructor() {
        this.outputChannel = vscode.window.createOutputChannel('curs');
    }

    init(context: vscode.ExtensionContext) {
        context.subscriptions.push(this.outputChannel);
    }

    public log(value: string = '') {
        return this.outputChannel.appendLine('[Info] ' + value);
    }

    public warning(value: string = '') {
        return this.outputChannel.appendLine('[WARNING] ' + value);
    }

    public error(value: string = '') {
		vscode.window.showErrorMessage('Error: ' + value);
        return this.outputChannel.appendLine('[Error] ' + value);
    }
 
	public appendLine(value: string = '') {
		return this.outputChannel.appendLine(value);
	}

	public append(value: string) {
		return this.outputChannel.append(value);
	}
}


export default new Logger();
