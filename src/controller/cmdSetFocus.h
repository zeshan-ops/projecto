/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#ifndef CMD_SETFOCUS_H
#define CMD_SETFOCUS_H

#include <vector>
#include <string>
#include "command.h"

class cmdSetFocus : public command {
    private:
        std::vector<std::string> args_;
    public:
        cmdSetFocus(std::vector<std::string> args);

        bool verifyArgs();
        std::string argErrorMessage();
        std::string execute();
};

#endif