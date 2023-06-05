#include "../doctest.h"

#include "../../src/model/jsonDataInterface.h"
#include <filesystem>
#include <sstream>

TEST_SUITE("JSON Data Interface Class Tests") {

    // Hard-coded test data string in json format
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

    TEST_CASE("Constructor member initialisation with sstream") {
        std::stringstream inputFile(testFile1Data.dump(3));
        jsonDataInterface testDataInterface(inputFile);

        CHECK(testDataInterface.getData() == testFile1Data);
    }

    ////////////////////////////////////////////////////////////////////////////////
    TEST_CASE("Return single JSON project from array of projects") {
        std::stringstream inputFile(testFile1Data.dump(3));
        jsonDataInterface testDataInterface(inputFile);

        json expectedProject = testFile1Data[0];
        CHECK(testDataInterface.getJSONProject("Test Project 1") == expectedProject);
    }

    ////////////////////////////////////////////////////////////////////////////////
    TEST_CASE("Checking if projects exist") {
        std::stringstream inputFile(testFile1Data.dump(3));
        jsonDataInterface testDataInterface(inputFile);

        SUBCASE("Existing project") {
            CHECK(testDataInterface.projectExists("Test Project 1"));
            CHECK(testDataInterface.projectExists("Test Project 2"));
            CHECK(testDataInterface.projectExists("Test Project 3"));
        }

        SUBCASE("Non-existing project") {
            CHECK(!testDataInterface.projectExists("Test Project"));
            CHECK(!testDataInterface.projectExists("Random test"));
        }
    }

    ////////////////////////////////////////////////////////////////////////////////
    TEST_CASE("Return complete Project object") {
        std::stringstream inputFile(testFile1Data.dump(3));
        jsonDataInterface testDataInterface(inputFile);

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

        CHECK(expectedProject.getTasks().size() == 3);
        CHECK(expectedProject.getLogs().size() == 3);
        CHECK(testDataInterface.getProject("Test Project 1") == expectedProject);
    }

    ////////////////////////////////////////////////////////////////////////////////
    TEST_CASE("Return Project object that has no tasks or logs") {
        std::stringstream inputFile(testFile1Data.dump(3));
        jsonDataInterface testDataInterface(inputFile);

        Project expectedProject("Test Project 3");

        CHECK(testDataInterface.getProject("Test Project 3") == expectedProject);
    }

    ////////////////////////////////////////////////////////////////////////////////
    TEST_CASE("Data editing method checks") {
        std::stringstream inputFile(testFile1Data.dump(3));
        jsonDataInterface testDataInterface(inputFile);

        SUBCASE("Replacing a project using JSON data") {
            json jsonProject = testDataInterface.getJSONProject("Test Project 1");
            jsonProject["projectName"] = "Edited test project";
            testDataInterface.editProjectJSON(jsonProject, "Test Project 1");

            CHECK(testDataInterface.getData().size() == 3);
            CHECK(testDataInterface.getJSONProject("Edited test project") == jsonProject);
        }

        SUBCASE("Replacing a project using a Project object") {
            Project projectData = testDataInterface.getProject("Test Project 1");
            Task newTask("Task 4");
            projectData.addTask(newTask);

            testDataInterface.editProject(projectData, "Test Project 1");

            CHECK(testDataInterface.getData().size() == 3);
            CHECK(testDataInterface.getProject("Test Project 1") == projectData);
            CHECK(testDataInterface.getProject("Test Project 1").getTasks().size() == 4);
            CHECK(testDataInterface.getProject("Test Project 1").getTask(3).getText() == "Task 4");
        }

        SUBCASE("Adding a new project") {
            json newProject;
            newProject["projectName"] = "New test project";
            newProject["tasks"];
            newProject["logs"];

            testDataInterface.addNewProjectJSON(newProject);

            CHECK(testDataInterface.getData().size() == 4);
            CHECK(testDataInterface.getJSONProject("New test project") == newProject);
            CHECK(testDataInterface.getJSONProject("New test project")["tasks"].size() == 0);
            CHECK(testDataInterface.getJSONProject("New test project")["logs"].size() == 0);
            
            Project projectTest = testDataInterface.getProject("New test project");
            CHECK(projectTest.getLogs().size() == 0);
            CHECK(projectTest.getTasks().size() == 0);
        }

        SUBCASE("Deleting a project") {
            testDataInterface.deleteProject("Test Project 1");

            CHECK(testDataInterface.getData().size() == 2);
            CHECK(testDataInterface.getData()[0]["projectName"] == "Test Project 2");
        }
    }

    ////////////////////////////////////////////////////////////////////////////////
    TEST_CASE("Data writing tests") {
        std::stringstream inputFile(testFile1Data.dump(3));
        jsonDataInterface testDataInterface(inputFile);

        testDataInterface.writeData("writingTest.json");

        std::ifstream inputFile2("writingTest.json");
        jsonDataInterface secondDataInterface(inputFile2);
        inputFile2.close();

        CHECK(secondDataInterface.getData() == testDataInterface.getData());
        CHECK(!inputFile2.is_open());
    }

    ////////////////////////////////////////////////////////////////////////////////
    /* This final test case just deletes all test files created during this test
    suite. */
    TEST_CASE("Delete test files") {
        int deleteFile2 = std::remove("writingTest.json");

        CHECK(deleteFile2 == 0);
    }
}