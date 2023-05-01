#include "viewUtilities.h"

std::string truncateText(std::string text, int truncLength) {
    std::string truncatedString = text.substr(0,truncLength-3);
    if(text.length() <= truncLength) {
        return text;
    }
    else {
        for(int i = 0; i < truncatedString.length(); i++){
            if(truncatedString[truncatedString.length()-i] == ' '){
                return (truncatedString.substr(0,truncatedString.length()-i) + "...");
            }
        }
    }
    return "Error truncating text";
}
