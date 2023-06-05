#include "cmdViewProject.h"

///////////////////////////////////////////////////////////////////////////////
cmdViewProject :: cmdViewProject(Project& project) : project_(project) {};

///////////////////////////////////////////////////////////////////////////////
std::string cmdViewProject :: execute() {
    std::vector<std::vector<std::string>> taskList;
    
    int taskID {0};
    for(auto& task : project_.getTasks()) {
        std::vector<std::string> taskStringVector = task.stringVector();
        taskStringVector.insert(taskStringVector.begin(), std::to_string(taskID));
        taskList.push_back(taskStringVector);
        ++taskID;
    }

    std::vector<std::string> lastAction;
    if(!project_.getLogs().empty()) {
        lastAction = project_.getLogs().back().stringVector();
    }

    std::vector<std::string> taskHeaders = {"ID", "Text", "P", "Due Date"};

    viewProject viewHandler(taskList, taskHeaders, lastAction, project_.getName());

    return viewHandler.render();
}