import * as vscode from 'vscode';
import logger from './logger';

// configuration variables
export let onSaveCoolDown: number | undefined;


export function validateConfiguration(): boolean {
	logger.log('Starting validating configurations...');

    const configuration = vscode.workspace.getConfiguration('curs');
	onSaveCoolDown = configuration.get<number>('onSaveCoolDown');

	logger.log(`onSaveCoolDown=${onSaveCoolDown}`);
	
	
	// validate configuration items exists
	if (!onSaveCoolDown) {
		logger.error('Mandatory configuration items missing!');
        return false;
    }

	onSaveCoolDown = onSaveCoolDown * 1000;  // transform into milliseconds

	logger.log(`Cool down time of on save events: ${onSaveCoolDown}`);
	return true;
}
