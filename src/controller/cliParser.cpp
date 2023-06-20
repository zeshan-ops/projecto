#include "cliParser.h"
#include "cmdViewProject.h"

///////////////////////////////////////////////////////////////////////////////
cliParser :: cliParser(std::vector<std::string> args) {
    // this sets the default command
    if (args.size() == 0) {
        args_.push_back("viewProject");
    } else {
        args_ = args;
    }
};

///////////////////////////////////////////////////////////////////////////////
bool cliParser :: commandExists() {
    std::vector<std::string> commandList {
        "viewProject", "viewDashboard",
        "viewLog", "viewTask",
        "viewLogs", "viewTasks",
        "editProjectName", "deleteProject", "addNewProject",
        "addTask", "editTask", "deleteTask",
        "addLog", "deleteLog",
        "setProject"
    };

    if(std::find(commandList.begin(),commandList.end(), args_[0]) != commandList.end()) {
        return true;
    }

    return false;
}

///////////////////////////////////////////////////////////////////////////////
std::unique_ptr<command> cliParser :: getCmdObject() {
    if (args_[0] == "viewProject") {
        args_.erase(args_.begin());
        return(std::make_unique<cmdViewProject>(args_));
    }
}