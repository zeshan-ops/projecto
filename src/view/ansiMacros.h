/*

ANSI Sequence Macros Defined For Cleaner Implementation In View Modules

*/

#ifndef ANSIMACROS_H
#define ANSIMACROS_H

// TEXT STATE MODIFIERS
#define txtReset "\033[0m"
#define txtBold "\033[1m"
#define txtDim "\033[2m"
#define txtItalic "\033[3m"
#define txtUnderline "\033[4m"
#define txtStrike "\033[9m"

// TEXT COLOURS
#define txtBlack "\033[30m"
#define txtRed "\033[31m"
#define txtGreen "\033[32m"
#define txtYellow "\033[33m"
#define txtBlue "\033[34m"
#define txtMagenta "\033[35m"
#define txtCyan "\033[36m"
#define txtWhite "\033[37m"

// BACKGROUND COLOURS
#define bgBlack "\033[90m"
#define bgRed "\033[91m"
#define bgGreen "\033[92m"
#define bgYellow "\033[93m"
#define bgBlue "\033[94m"
#define bgMagenta "\033[95m"
#define bgCyan "\033[96m"
#define bgWhite "\033[97m"

#endif