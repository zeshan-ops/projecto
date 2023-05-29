#include "viewUtilities.h"

std::string viewUtil :: truncateText(std::string text, unsigned int truncLength) {    
    if(truncLength == 0) {
        return text;
    }

    if(text.length() == 0) {
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
    for(unsigned int i = 1; i < std::ceil(text.length()/lineLength) + 1; i ++) {
        for(unsigned int j = 0; j < lineLength; j++) {
            if((lineLength*i) > text.length()){
                break;
            }
            else {
                if(text[(lineLength*i)-j] == ' '){
                    text.at((lineLength*i)-j) = '\n';
                    break;
                }
            }
        }
    }

    return text;
}
