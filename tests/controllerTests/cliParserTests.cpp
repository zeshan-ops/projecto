#include "../doctest.h"
#include "../../src/controller/cliParser.h"
#include "../../src/controller/cmdViewProject.h"
#include <filesystem>

TEST_SUITE("Controller: cliParser Class Tests") {
    TEST_CASE("Command_exists() tests") {
        std::vector<std::string> validCommandList {
            "viewProject", "viewDashboard",
            "viewLog", "viewTask",
            "viewLogs", "viewTasks",
            "editProjectName", "deleteProject", "addNewProject",
            "addTask", "editTask", "deleteTask",
            "addLog", "deleteLog",
            "setFocus"
        };

        for(auto& cmd : validCommandList) {
            std::vector<std::string> cmdArgs = {
                "cmd", "arg1", "arg2", "arg3"
            };
            
            cmdArgs[0] = cmd;

            cliParser cmdChooser(cmdArgs);
            CHECK(cmdChooser.commandExists());
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
            CHECK(!cmdChooser.commandExists());
        }
    }

    TEST_CASE("Default command check") {
        std::vector<std::string> emptyArgs;

        cliParser cmdChooser(emptyArgs);
        CHECK(cmdChooser.commandExists());
    }
}