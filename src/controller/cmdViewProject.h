/*

Construct with reference to Project,
will convert the Project to a view (string) on execute.

*/

#ifndef CMD_VIEWPROJECT_H
#define CMD_VIEWPROJECT_H

#include "command.h"

#include <string>
#include <iostream>
#include <vector>

class cmdViewProject : public command {
    private:
        std::vector<std::string> args_;
    public:
        cmdViewProject(std::vector<std::string> args);

        bool verifyArgs();
        std::string argErrorMessage();
        std::string execute();
};

#endif