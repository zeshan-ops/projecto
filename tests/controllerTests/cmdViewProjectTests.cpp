#include <sstream>
#include <string>
#include <iostream>
#include <fstream>

#include "../doctest.h"
#include "../../src/controller/cmdViewProject.h"
#include "../../src/view/ansiMacros.h"
#include "../../src/model/project.h"
#include "../../src/model/json.hpp"

using nlohmann::json;

TEST_SUITE("Controller: cmdViewProject Class Tests") {
    TEST_CASE("Running a fully fleshed project, with valid CLI input") {
        std::stringstream composer;
            
        composer << "\n";
        composer << txtBold << txtGreen << "                                 Test Project 1";
        composer << "\n\n";
        composer << "TASKS" << txtReset << "\n";
        composer 
            << "\033[4m\033[1mID\033[0m \033[4m\033[1mText                                                           \033[0m \033[4m\033[1mP\033[0m \033[4m\033[1mDue Date  \033[0m\n" 
            << "0  Blurg farg jork lorem                                           H 2023-02-02\n"
            << "1  Blurg farg jork lorem                                           H 2023-02-03\n"
            << "2  Blurg farg jork lorem ipsum dolores, truncation galore my...    M 2023-02-03\n"
            << "3  Blurg farg jork lorem                                           L 2023-02-03\n";
        composer << txtDim << "(4 tasks)" << txtReset << "\n";
        composer << "\n";

        composer << txtGreen << txtBold << "LAST ACTION" << txtReset;
        composer << "\n";
        composer << txtBold << txtDim << "2023-06-01 10:42:54" << txtReset;
        composer << "\n";
        composer << "Lorem ipsum dolores, equitat vai sorquet epilin aquila et vac, loresium dolorium\nthe quick brown fox jumper over the lazy dog. Monkeys bashing keyboards would\neventually write the entire works of Shakespeare. Seek the truth, return to the\npath. Etc bon soir mon cherie.";    
        composer << "\n";

        std::string expectedString = composer.str();

        json testFile1Data = json::parse(R"([
        {
            "projectName": "Test Project 1",
            "tasks": [
                {
                    "text": "Blurg farg jork lorem",
                    "urgency": 3,
                    "dueDate": "2023-02-02",
                    "completed": false
                },
                {
                    "text": "Blurg farg jork lorem",
                    "urgency": 3,
                    "dueDate": "2023-02-03",
                    "completed": false
                },
                {
                    "text": "Blurg farg jork lorem ipsum dolores, truncation galore my dear Watson",
                    "urgency": 2,
                    "dueDate": "2023-02-03",
                    "completed": false
                },
                {
                    "text": "Blurg farg jork lorem",
                    "urgency": 1,
                    "dueDate": "2023-02-03",
                    "completed": false
                }
            ],
            "logs": [
                {
                    "text": "Lorem ipsum dolores, equitat vai sorquet epilin aquila et vac, loresium dolorium the quick brown fox jumper over the lazy dog. Monkeys bashing keyboards would eventually write the entire works of Shakespeare. Seek the truth, return to the path. Etc bon soir mon cherie.",
                    "time": "2023-06-01 10:42:54"
                },
                {
                    "text": "Log 2",
                    "time": "2020-01-01 17:10:00"
                },
                {
                    "text": "Log 3",
                    "time": "2020-01-01 17:15:00"
                }
            ]
        },
        {
            "projectName": "Test Project 2",
            "tasks": [
                {
                    "text": "Task 1",
                    "urgency": 0,
                    "dueDate": "2020-01-01",
                    "completed": false
                },
                {
                    "text": "Task 2",
                    "urgency": 1,
                    "dueDate": "2020-01-02",
                    "completed": false
                },
                {
                    "text": "Task 3",
                    "urgency": 2,
                    "dueDate": "2020-01-03",
                    "completed": false
                }
            ],
            "logs": [
                {
                    "text": "Log 1",
                    "time": "2020-01-01 17:00:00"
                },
                {
                    "text": "Log 2",
                    "time": "2020-01-01 17:10:00"
                },
                {
                    "text": "Log 3",
                    "time": "2020-01-01 17:15:00"
                }
            ]
        },
        {
            "projectName": "Test Project 3",
            "tasks": [],
            "logs": []
        }
        ])");

        // Creating a mock data directory
        std::string dataPath = (std::string)std::getenv("HOME") + "/.projecto";

        // data file creation
        std::filesystem::create_directory(dataPath);
        std::ofstream outputFile(dataPath + "/data.json");
        outputFile << testFile1Data;
        outputFile.close();

        // init file creation
        std::string initFileText = "FOCUSED_PROJECT\nTest Project 1";
        std::ofstream outputInitFile(dataPath + "/initial.txt");

        outputInitFile << initFileText;
        outputInitFile.close();

        // testing the cmdViewProject object
        std::vector<std::string> args;
        cmdViewProject cmd(args);

        CHECK(cmd.verifyArgs() == true);
        CHECK(cmd.execute() == expectedString);

        std::filesystem::remove_all(dataPath);
        CHECK(!std::filesystem::exists(dataPath));
    }

    TEST_CASE("Behaviour when no focused project is set") {
        std::string dataPath = (std::string)std::getenv("HOME") + "/.projecto";

        std::vector<std::string> args;
        cmdViewProject cmd(args);

        CHECK(cmd.verifyArgs() == true);
        CHECK(cmd.execute() == "No focused project set. To set a focused project, use:\nprojecto setFocus <PROJECT NAME>\n");

        std::filesystem::remove_all(dataPath);
        CHECK(!std::filesystem::exists(dataPath));
    }

    TEST_CASE("Behaviour when focused project is set but cannot be found") {
        std::string dataPath = (std::string)std::getenv("HOME") + "/.projecto";
        std::filesystem::create_directory(dataPath);

        std::string initFileText = "FOCUSED_PROJECT\nRandom project name that doesn't exist";
        std::ofstream outputInitFile(dataPath + "/initial.txt");
        outputInitFile << initFileText;
        outputInitFile.close();

        std::vector<std::string> args;
        cmdViewProject cmd(args);

        CHECK(cmd.execute() == "Focused project not found. To set a focused project, use:\nprojecto setFocus <PROJECT NAME>\n");

        std::filesystem::remove_all(dataPath);
        CHECK(!std::filesystem::exists(dataPath));
    }
}