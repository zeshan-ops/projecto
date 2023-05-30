#include "../doctest.h"
#include "../../src/controller/cliParser.h"

TEST_SUITE("CLI Parser Tests") {
    TEST_CASE("Command_exists() tests") {
        std::vector<std::string> validCommandList {
            "viewProject", "viewDashboard",
            "viewLog", "viewTask",
            "viewLogs", "viewTasks",
            "editProjectName", "deleteProject", "addNewProject",
            "addTask", "editTask", "deleteTask",
            "addLog", "deleteLog",
            "setProject"
        };

        for(auto& cmd : validCommandList) {
            std::vector<std::string> cmdArgs = {
                "cmd", "arg1", "arg2", "arg3"
            };
            
            cmdArgs[0] = cmd;

            cliParser cmdChooser(cmdArgs);
            CHECK(cmdChooser.command_exists());
        }

        std::vector<std::string> invalidCommandList {
            "viewProject1",
            "viewLog1", "viewTask1",
            "viewLogss", "viewTasksw",
            "addTask2", "editTask54", "deleteTask5",
            "addLo2g", "deleteL2og",
            "setProj3ect",
            "blah", "foo", "gah"
        };

        for(auto& cmd : invalidCommandList) {
            std::vector<std::string> cmdArgs = {
                "cmd", "arg1", "arg2", "arg3"
            };

            cmdArgs[0] = cmd;

            cliParser cmdChooser(cmdArgs);
            CHECK(!cmdChooser.command_exists());
        }
    }
}