/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#ifndef CLIPARSER_H
#define CLIPARSER_H

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include "command.h"

class cliParser {
    private:
        std::vector<std::string> args_;
    public:
        cliParser(std::vector<std::string> args);

        bool commandExists();
        std::unique_ptr<command> getCmdObject();
};

#endif