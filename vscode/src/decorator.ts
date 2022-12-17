import * as vscode from 'vscode';
import logger from './logger';


/**
 * Color scheme:
 * Function name highlight: #8F8800
 * Profiling text:
 *   no impact: #7CC36E
 *   low impact: #CCC948
 *   medium impact: #D0AB4B
 *   high impact: #D44E40
 */


/**
 * Object representing a single profiling result
 * The profiling result contains the function name (text to be highlighted),\
 * the decoration range, and text content to be displayed
 */
export interface ProfilingEntry {
    profilingIndex: string,
    startLine: number,
    startCol: number,
    endLine: number,
    endCol: number,
    triggerFile: string,
    suggestedAction: string,
    suggestedSnippet: string
};

/**
 * This dictionary of dictionary contains all currently applied decorations
 * The storage structure is {fileName: {profilingIndex: DecorationOptions, ...}} 
 */
interface DecorationMap {
    [key: string]: {
        [key: string]: vscode.DecorationOptions
    }
};

export const tracedFiles: Set<string> = new Set();
const textDecorations: DecorationMap = {};
const backgroundDecorations: DecorationMap = {};

// Template decoration type for adding time consumption after function declaration line
const textDecorationType = vscode.window.createTextEditorDecorationType({
    after: { margin: '0 0 0 1rem' },
    rangeBehavior: vscode.DecorationRangeBehavior.OpenClosed
});

// Template decoration type for adding highlight to target text (function name)
const backgroundDecorationType = vscode.window.createTextEditorDecorationType({
    backgroundColor: '#8F8800'
});


/**
 * External function, call this function to flush all decorations applied to the target file with the given profiling results
 * @param fileName Target file where the decorations to be flushed 
 * @param profilingResults Profiling results, should contains line number of each function declaration and corresponding time consumption
 */
export function flushDecorations(fileName: string, profilingResult: ProfilingEntry[]): void {
    logger.log(`Flushing decorations on file ${fileName}...`);
    
    // clear decorations applied to the target file
    textDecorations[fileName] = {};
    backgroundDecorations[fileName] = {};
    tracedFiles.add(fileName);

    profilingResult.forEach(profilingEntry => {
        decorate(profilingEntry, fileName);
    });
    refreshDecorations(fileName);
}


/**
 * External function, clear decorations applied on a specific file
 * @param fileName Target file where the decorations to be removed 
 */
export function removeDecorations(fileName: string) {
    if (tracedFiles.has(fileName)) {
        logger.log(`Removing decorations on file ${fileName}...`);
        textDecorations[fileName] = {};
        backgroundDecorations[fileName] = {};
        refreshDecorations(fileName);
        tracedFiles.delete(fileName);
    }
}


/**
 * External function, clear all decorations applied on each of the opened editor windows
 */
export function clearDecorations(): void {
    logger.log(`Clearing decorations...`);
    vscode.window.visibleTextEditors.forEach(textEditor => {
        // If rangesOrOptions is empty, the existing decorations with the given decoration type will be removed
        textEditor.setDecorations(textDecorationType, []);
        textEditor.setDecorations(backgroundDecorationType, []);
        return;
    });
    tracedFiles.clear();
}


/**
 * external function, update rendering for opened editor windows of the target file
 * @param fileName Target file name for rendering decoration
 */
 export function refreshDecorations(fileName: string): void {
    //logger.log(JSON.stringify(tracedFiles.keys()));
    if (tracedFiles.has(fileName)) {
        logger.log(`Refreshing decorations for file ${fileName}...`);
        getEditors(fileName).forEach(textEditor => {
            textEditor.setDecorations(
                textDecorationType,
                Object.values(textDecorations[fileName])
                //Array.prototype.concat.apply([], Object.values(textDecorations[fileName]))
            );
            textEditor.setDecorations(
                backgroundDecorationType,
                Object.values(backgroundDecorations[fileName])
                //Array.prototype.concat.apply([], Object.values(backgroundDecorations[fileName]))
            );
        });
    }
}


/**
 * Internal function, add time estimation decoration at a specific line
 * @param text Text to be showed
 * @param lineNo Line number where the decoration would be rendered, starting from 1
 * @param fileName Target file name for rendering decoration
 */
function decorate(profilingEntry: ProfilingEntry, fileName: string): void {
    const profilingIndex = profilingEntry.profilingIndex;
    const startLine = profilingEntry.startLine;
    const startCol = profilingEntry.startCol;
    const endLine = profilingEntry.endLine;
    const endCol = profilingEntry.endCol;
    const triggerFile = profilingEntry.triggerFile;
    const suggestedAction = profilingEntry.suggestedAction;
    const suggestedSnippet = profilingEntry.suggestedSnippet;

    const markdownContent = new vscode.MarkdownString()
    markdownContent.appendMarkdown(`<span style="color:#fff;background-color:#777;">&nbsp;&nbsp;&nbsp;Trigger: &nbsp;&nbsp;&nbsp;</span>&nbsp;&nbsp;&nbsp;${triggerFile}`);
    markdownContent.appendText('\n');
    markdownContent.appendMarkdown(`<span style="color:#fff;background-color:#777;">&nbsp;&nbsp;&nbsp;Suggestion: &nbsp;&nbsp;&nbsp;</span>&nbsp;&nbsp;&nbsp;${suggestedAction}`);
    markdownContent.appendText('\n');

    const encodedArgs = encodeURIComponent(JSON.stringify(profilingEntry));
    if (suggestedAction) {
        markdownContent.appendCodeblock(suggestedSnippet, 'c');
        markdownContent.appendText('\n');
        markdownContent.appendMarkdown(`[accept](command:PatternRefactor.accept?${encodedArgs})    [ignore](command:PatternRefactor.ignore?${encodedArgs})`);
    } else {
        markdownContent.appendMarkdown(`accept    [ignore](command:PatternRefactor.ignore?${encodedArgs})`);
    }
    markdownContent.isTrusted = true;
    // assume the performance text only added to the end of decoration range
    logger.log(`Add decoration ${profilingIndex} in ${fileName}. Trigger: ${triggerFile}`);
    const textDecoration = {
        range: new vscode.Range(endLine, Number.MAX_SAFE_INTEGER, endLine, Number.MAX_SAFE_INTEGER),
        renderOptions: { after: { contentText: triggerFile, color: getDecorationColor(triggerFile) } },
        hoverMessage: markdownContent
    };
    textDecorations[fileName][profilingIndex] = textDecoration;

    // highlight the whole decoration range
    const backgroundDecoration: vscode.DecorationOptions = {
        range: new vscode.Range(startLine, startCol, endLine, endCol),
        hoverMessage: markdownContent
    };
    backgroundDecorations[fileName][profilingIndex] = backgroundDecoration;
}


export function acceptSuggestion(editor: vscode.TextEditor, edit: vscode.TextEditorEdit, profilingEntry: ProfilingEntry) {
    logger.log(JSON.stringify(profilingEntry));
    switch (profilingEntry.suggestedAction) {
        case 'replace':
            edit.replace(
                new vscode.Range(profilingEntry.startLine, profilingEntry.startCol, profilingEntry.endLine, profilingEntry.endCol),
                profilingEntry.suggestedSnippet
            );
            break;

        case 'add':
            edit.insert(new vscode.Position(profilingEntry.endLine, profilingEntry.endCol), profilingEntry.suggestedSnippet);
            break;

        case 'delete':
            edit.delete(new vscode.Range(profilingEntry.startLine, profilingEntry.startCol, profilingEntry.endLine, profilingEntry.endCol));
            break;

        default:
            logger.error(`Failed to parse suggested action ${profilingEntry.suggestedAction}`);
    }
    editor.document.save();
    ignoreSuggestion(editor, edit, profilingEntry);
}


export function ignoreSuggestion(editor: vscode.TextEditor, edit: vscode.TextEditorEdit, profilingEntry: ProfilingEntry) {
    const fileName = editor.document.fileName;
    if (editor) {
        delete textDecorations[fileName][profilingEntry.profilingIndex];
        delete backgroundDecorations[fileName][profilingEntry.profilingIndex];
    }
    refreshDecorations(fileName);
}


function getDecorationColor(displayContent: string): string {
    return '#D44E40';
}


/**
 * Utility function, filter out the windows that opened the specific file from all current opened editor windows
 * @param fileName Name of the target file
 * @returns A list of editor objects containing the target file
 */
function getEditors(fileName: string): vscode.TextEditor[] {
    return vscode.window.visibleTextEditors.filter(editor => editor.document.fileName === fileName);
}
