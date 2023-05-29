/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#ifndef VIEWTASK_H
#define VIEWTASK_H

#include "viewDetail.h"

class viewTask {
    private:
        std::vector<std::string> taskContent;
        std::vector<std::string> taskHeaders;
    public:
        viewTask(std::vector<std::string> taskContent, std::vector<std::string> taskHeaders);

        void render();
};

#endif