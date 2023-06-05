/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#ifndef CMD_VIEWPROJECT_H
#define CMD_VIEWPROJECT_H

#include "../view/viewProject.h"
#include "../model/jsonDataInterface.h"
#include "../model/project.h"
#include "command.h"
#include <string>

class cmdViewProject : public command {
    private:
        Project& project_;
    public:
        cmdViewProject(Project& project);
        std::string execute();
};

#endif