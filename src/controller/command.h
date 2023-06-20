/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#ifndef COMMAND_H
#define COMMAND_H

#include <string>

class command {
    public:
        virtual ~command() {};
        virtual bool verifyArgs() = 0;
        virtual std::string argErrorMessage() = 0;
        virtual std::string execute() = 0;
};

#endif