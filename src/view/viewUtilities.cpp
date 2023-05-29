#include "viewUtilities.h"

std::string viewUtil :: truncateText(std::string text, unsigned int truncLength) {    
    if(truncLength == 0 || text.length() == 0) {
        return text;
    }

    if(text.length() <= truncLength) {
        return text;
    } 
    else {
        std::string truncatedString = text.substr(0,truncLength);
        for(unsigned int i = 0; i < truncatedString.length(); i++){
            if(truncatedString[truncatedString.length()-i] == ' '){
                return (truncatedString.substr(0,truncatedString.length()-i) + "...");
            } 
        }
        return truncatedString.substr(0,truncatedString.length()-3) + "...";
    }
}

std::string viewUtil :: wrapText(std::string text, unsigned int lineLength) {
    if(text.length() == 0 || lineLength == 0) {
        return "";
    }
    
    if(text.length() <= lineLength) {
        return text;
    }

    for(unsigned int i = 0; i < std::ceil(text.length()/lineLength); i ++) {
        for(unsigned int j = 0; j < lineLength; j++) {
                if(text[(lineLength*(i+1)-j+1)] == ' '){
                    text.at((lineLength*(i+1)-j+1)) = '\n';
                    break;
                }
        }
    }
    return text;
}