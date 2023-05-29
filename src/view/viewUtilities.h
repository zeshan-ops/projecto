/*

Utility functions for outputting to the terminal

*/

#ifndef VIEWUTIL_H
#define VIEWUTIL_H

#include <string>
#include <cmath>

namespace viewUtil {
    // text truncation, adds an ellipsis to end of truncated text
    std::string truncateText(std::string text, unsigned int truncLength);

    std::string wrapText(std::string text, unsigned int lineLength);
};

#endif