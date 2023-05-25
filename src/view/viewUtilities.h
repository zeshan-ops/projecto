/*

Utility functions for outputting to the terminal

*/

#ifndef VIEWUTIL_H
#define VIEWUTIL_H

#include<string>

namespace viewUtil {
    // text truncation, adds an ellipsis to end of truncated text
    std::string truncateText(std::string text, int truncLength);

};

#endif