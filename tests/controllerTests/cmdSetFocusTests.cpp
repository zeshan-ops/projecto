#include "../doctest.h"
#include "../../src/controller/cmdSetFocus.h"
#include "../../src/model/json.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>

using nlohmann::json;

TEST_SUITE("Controller: cmdSetFocus Class Tests") {
    TEST_CASE("verifyArgs() tests") {
        SUBCASE("One argument supplied") {
            cmdSetFocus cmdTester({"One"});
            CHECK(!cmdTester.verifyArgs());
        }

        SUBCASE("Two arguments supplied") {
            cmdSetFocus cmdTester({"One", "Two"});
            CHECK(cmdTester.verifyArgs());
        }

        SUBCASE("Three arguments supplied") {
            cmdSetFocus cmdTester({"One", "Two", "Three"});
            CHECK(!cmdTester.verifyArgs());
        }
    }

    TEST_CASE("execute() with empty data file") {
        cmdSetFocus cmdTester({"setFocus", "Test Project 1"});
        std::string expectedOutput = "\nError: \"Test Project 1\" could not be found in data file. \n To see a list of stored projects use: \nprojecto projects\n";
        CHECK(cmdTester.execute() == expectedOutput);

        std::string dataPath = (std::string)std::getenv("HOME") + "/.projecto";
        std::filesystem::remove_all(dataPath);
        CHECK(!std::filesystem::exists(dataPath));
    }

    TEST_CASE("execute() with full data file") {
        // creating mock data files
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

        SUBCASE("Valid project name") {
            cmdSetFocus cmdTester({"setFocus", "Test Project 2"});
            std::string expectedOutput = "\nFocused project has been set to \"Test Project 2.\"\n";
            CHECK(cmdTester.execute() == expectedOutput);
        }

        SUBCASE("Invalid project name") {
            cmdSetFocus cmdTester({"setFocus", "Invalid project name"});
            std::string expectedOutput = "\nError: \"Invalid project name\" could not be found in data file. \n To see a list of stored projects use: \nprojecto projects\n";
            CHECK(cmdTester.execute() == expectedOutput);
        }

        std::filesystem::remove_all(dataPath);
        CHECK(!std::filesystem::exists(dataPath));
    }
}