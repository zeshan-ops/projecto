/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#ifndef COMMAND_H
#define COMMAND_H

#include <string>

class command {
    public:
        virtual std::string execute() = 0;
};

#endif