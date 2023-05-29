/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#ifndef PROJECT_OVERVIEW_H
#define PROJECT_OVERVIEW_H

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "ansiMacros.h"
#include "viewTable.h"

class viewProject {
    private:
        std::vector<std::vector<std::string>> tasks;
        std::vector<std::string> taskHeaders;
        std::vector<std::string> lastAction;
        std::string projectName;
    public:
        viewProject(std::vector<std::vector<std::string>> tList, 
                    std::vector<std::string> tHeaders,
                    std::vector<std::string> last, 
                    std::string name);

        std::string render();
};

#endif