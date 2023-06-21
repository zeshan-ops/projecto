#include "cliParser.h"
#include "cmdViewProject.h"
#include "cmdSetFocus.h"

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
        "setFocus"
    };

    if(std::find(commandList.begin(),commandList.end(), args_[0]) != commandList.end()) {
        return true;
    }

    return false;
}

///////////////////////////////////////////////////////////////////////////////
std::unique_ptr<command> cliParser :: getCmdObject() {
    if (args_[0] == "viewProject") {
        return (std::make_unique<cmdViewProject>(args_));
    }

    else if (args_[0] == "setFocus") {
        return (std::make_unique<cmdSetFocus>(args_));
    }

    else {
        args_.clear();
        return (std::make_unique<cmdViewProject>(args_));
    }
}