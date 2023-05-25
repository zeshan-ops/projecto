/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#ifndef PROJECT_OVERVIEW_H
#define PROEJCT_OVERVIEW_H

#include <vector>
#include <string>
#include <iostream>
#include "../model/task.h"
#include "../model/log.h"
#include "ansiMacros.h"


namespace projectView {
    void renderTaskTable(const std::vector<Task>& taskList);
    void renderLastAction(const Log lastAction);
    void renderView(const std::vector<Task>& taskList, const Log lastAction);
}

#endif