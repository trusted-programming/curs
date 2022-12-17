import * as vscode from 'vscode';


class Status {
    private readonly statusBar: vscode.StatusBarItem;
    private _isBusy: boolean = false;

    constructor() {
        this.statusBar = vscode.window.createStatusBarItem(vscode.StatusBarAlignment.Left);
        this.statusBar.hide();
    }
    
    init(context: vscode.ExtensionContext) {
        context.subscriptions.push(this.statusBar);
    }

    isBusy(): boolean {
        return this._isBusy;
    }
    startValidation() {
        this._isBusy = true;
        this.statusBar.show();
        this.statusBar.text = '$(loading~spin) Validating settings...';
    }

    startUploading() {
        this.statusBar.text = '$(loading~spin) Uploading files...';
    }

    startDetection() {
        this.statusBar.text = '$(loading~spin) Detecting patterns...';
    }

    endExecution() {
        this.statusBar.hide();
        this._isBusy = false;
    }
}


export default new Status();
