import { exec, ExecException } from 'child_process';
import logger from './logger';
import { StatusBarAlignment } from 'vscode';


export function remoteCall(sourceFilePath: string,
    callback: (error: ExecException | null, stdout: string, stderr: string) => void,
    timeout: number = 30000) {
    var remoteCommand: string = `LD_LIBRARY_PATH=~/.cargo/bin rust_hero ${sourceFilePath}`;
    logger.log(`Executing command: ${remoteCommand}`);
    exec(remoteCommand, {timeout: timeout}, callback);    
}
