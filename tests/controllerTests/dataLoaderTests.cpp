#include "../doctest.h"
#include "../../src/controller/dataLoader.h"

TEST_SUITE("Controller: dataLoader Class Tests") {
    TEST_CASE("Creating data file when it does not exist as part of the constructor") {
        std::string dataPath = (std::string)std::getenv("HOME") + "/.projecto";

        std::filesystem::remove_all(dataPath);
        std::filesystem::create_directory(dataPath);

        dataLoader loadedData("Blank project name");

        CHECK(std::filesystem::exists(dataPath + "/data.json"));

        std::filesystem::remove_all(dataPath);
        CHECK(!std::filesystem::exists(dataPath));
    }

    TEST_CASE("Returning correct data objects") {
        std::string dataPath = (std::string)std::getenv("HOME") + "/.projecto";

        std::filesystem::create_directory(dataPath);

        json testFile1Data = json::parse(R"([
        {
            "projectName": "Test Project 1",
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

        std::ofstream outputFile(dataPath + "/data.json");

        outputFile << testFile1Data;
        outputFile.close();

        SUBCASE("Returning correct project object") {
            Project expectedProject("Test Project 1");

            Task task1("Task 1", 0, floor<days>(sys_days{2020_y/1/1}));
            Task task2("Task 2", 1, floor<days>(sys_days{2020_y/1/2}));
            Task task3("Task 3", 2, floor<days>(sys_days{2020_y/1/3}));

            expectedProject.addTask(task1); 
            expectedProject.addTask(task2); 
            expectedProject.addTask(task3);

            Log log1("Log 1");
            log1.setTime(sys_days{2020_y/1/1} + 17h + 0min + 0s);

            Log log2("Log 2");
            log2.setTime(sys_days{2020_y/1/1} + 17h + 10min + 0s);
        
            Log log3("Log 3");
            log3.setTime(sys_days{2020_y/1/1} + 17h + 15min + 0s);

            expectedProject.addLog(log1); 
            expectedProject.addLog(log2); 
            expectedProject.addLog(log3);

            dataLoader loadedData("Test Project 1");
            CHECK(loadedData.getProject() == expectedProject);
        }

        std::filesystem::remove_all(dataPath);
        CHECK(!std::filesystem::exists(dataPath));

    }
}