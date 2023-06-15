#include "cliParser.h"

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
/*
command& cliParser :: getCmdObject() {
    if (args_[0] == "viewProject") {
        cmdViewProject cmd;
        return cmd;
    }
    else {
        cmdViewProject cmd;
        return cmd;
    }
}
*/