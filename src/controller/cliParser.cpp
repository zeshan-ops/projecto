#include "cliParser.h"

///////////////////////////////////////////////////////////////////////////////
cliParser :: cliParser(std::vector<std::string> args) : args(args) {};

///////////////////////////////////////////////////////////////////////////////
bool cliParser :: command_exists() {
    std::vector<std::string> commandList {
        "viewProject", "viewDashboard",
        "viewLog", "viewTask",
        "viewLogs", "viewTasks",
        "editProjectName", "deleteProject", "addNewProject",
        "addTask", "editTask", "deleteTask",
        "addLog", "deleteLog",
        "setProject"
    };

    if(std::find(commandList.begin(),commandList.end(), args[0]) != commandList.end()) {
        return true;
    }

    return false;
}