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
        command& cmd = argParser.getCmdObject();
        if (cmd.verifyArgs()) {
            std::cout << cmd.execute();
            return 0;
        } 
        else {
            std::cout << cmd.errorMessage();
            return 0;
        }
    } 
    else {
        // print error message
        return 0;
    }
}