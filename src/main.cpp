/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#include <iostream>
#include <vector>
#include <string>
#include "controller/cliParser.h"

int main(int argc, char* argv[]){
    std::vector<std::string> arguments;
    
    if (argc > 1) {
        std::vector<std::string> manyArgs (argv + 1, argv + argc);
        arguments = manyArgs;
    }

    cliParser argParser(arguments);

    if (argParser.commandExists()) {
        if (argParser.getCmdObject()->verifyArgs()) {
            std::cout << argParser.getCmdObject()->execute();
            return 0;
        } 
        else {
            std::cout << argParser.getCmdObject()->argErrorMessage();
            return 0;
        }
    } 
    else {
        std::cout << "Unrecognised command.\n";
        return 0;
    }
}