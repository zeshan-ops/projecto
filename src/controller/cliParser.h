/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#ifndef CLIPARSER_H
#define CLIPARSER_H

#include <iostream>
#include <string>
#include <vector>
#include <tuple>

class cliParser {
    private:
        std::vector<std::string> args;
    public:
        cliParser(std::vector<std::string> args);

        bool command_exists();
};

#endif