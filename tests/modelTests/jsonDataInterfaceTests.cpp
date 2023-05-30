#include "../doctest.h"

#include "../../src/model/jsonDataInterface.h"
#include <filesystem>

TEST_SUITE("JSON Data Interface Class Tests") {

    // testFile1 raw data
    json testFile1Data = json::parse(R"([
    {
        "projectName": "Test Project 1",
        "tasks": [
            {
                "text": "Task 1",
                "urgency": 0,
                "dueDate": 0,
                "completed": false
            },
            {
                "text": "Task 2",
                "urgency": 1,
                "dueDate": 1,
                "completed": false
            },
            {
                "text": "Task 3",
                "urgency": 2,
                "dueDate": 2,
                "completed": false
            }
        ],
        "logs": [
            {
                "text": "Log 1",
                "time": 0
            },
            {
                "text": "Log 2",
                "time": 1
            },
            {
                "text": "Log 3",
                "time": 2
            }
        ]
    },
    {
        "projectName": "Test Project 2",
        "tasks": [
            {
                "text": "Task 1",
                "urgency": 0,
                "dueDate": 0,
                "completed": false
            },
            {
                "text": "Task 2",
                "urgency": 1,
                "dueDate": 1,
                "completed": false
            },
            {
                "text": "Task 3",
                "urgency": 2,
                "dueDate": 2,
                "completed": false
            }
        ],
        "logs": [
            {
                "text": "Log 1",
                "time": 0
            },
            {
                "text": "Log 2",
                "time": 1
            },
            {
                "text": "Log 3",
                "time": 2
            }
        ]
    },
    {
        "projectName": "Test Project 3",
        "tasks": [],
        "logs": []
    }
    ])");


    ////////////////////////////////////////////////////////////////////////////////
    /* This first test case works as a setup for this test suite, it just creates
    the JSON test file to be used in subsequent test cases. This was done because I
    couldn't figure out an alternative way to create a test file in doctest without
    using a separate file/executable that would run first and create the test files.
    This way just seems easier. */
    TEST_CASE("Creating test file") {
        std::ofstream testFile1("testFile1.json");

        testFile1 << testFile1Data.dump(3);
        testFile1.close();
    }

    ////////////////////////////////////////////////////////////////////////////////
    TEST_CASE("Constructor member initialisation") {
        std::ifstream inputFile("testFile1.json");
        jsonDataInterface testDataInterface(inputFile);

        CHECK(testDataInterface.getData() == testFile1Data);
        CHECK(!inputFile.is_open());
    }

    ////////////////////////////////////////////////////////////////////////////////
    TEST_CASE("Return single JSON project from array of projects") {
        std::ifstream inputFile("testFile1.json");
        jsonDataInterface testDataInterface(inputFile);

        json expectedProject = testFile1Data[0];
        CHECK(testDataInterface.getJSONProject("Test Project 1") == expectedProject);
        CHECK(!inputFile.is_open());
    }

    ////////////////////////////////////////////////////////////////////////////////
    TEST_CASE("Return complete Project object") {
        std::ifstream inputFile("testFile1.json");
        jsonDataInterface testDataInterface(inputFile);

        Project expectedProject("Test Project 1");
        Task task1("Task 1");
        Task task2("Task 2"); task2.setUrgency(1); task2.setDueDate(1);
        Task task3("Task 3"); task3.setUrgency(2); task3.setDueDate(2);

        expectedProject.addTask(task1); expectedProject.addTask(task2); expectedProject.addTask(task3);

        Log log1("Log 1", 0);
        Log log2("Log 2", 1);
        Log log3("Log 3", 2);
        expectedProject.addLog(log1); expectedProject.addLog(log2); expectedProject.addLog(log3);

        CHECK(testDataInterface.getProject("Test Project 1") == expectedProject);
        CHECK(!inputFile.is_open());
    }

    ////////////////////////////////////////////////////////////////////////////////
    TEST_CASE("Return Project object that has no tasks or logs") {
        std::ifstream inputFile("testFile1.json");
        jsonDataInterface testDataInterface(inputFile);

        Project expectedProject("Test Project 3");

        CHECK(testDataInterface.getProject("Test Project 3") == expectedProject);
        CHECK(!inputFile.is_open());
    }

    ////////////////////////////////////////////////////////////////////////////////
    TEST_CASE("Data editing method checks") {
        std::ifstream inputFile("testFile1.json");
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
        std::ifstream inputFile("testFile1.json");
        jsonDataInterface testDataInterface(inputFile);

        testDataInterface.writeData("writingTest.json");

        std::ifstream inputFile2("writingTest.json");
        jsonDataInterface secondDataInterface(inputFile2);

        CHECK(secondDataInterface.getData() == testDataInterface.getData());
        CHECK(!inputFile.is_open());
        CHECK(!inputFile2.is_open());
    }

    ////////////////////////////////////////////////////////////////////////////////
    /* This final test case just deletes all test files created during this test
    suite. */
    TEST_CASE("Delete test files") {
        int deleteFile1 = std::remove("testFile1.json");
        int deleteFile2 = std::remove("writingTest.json");

        CHECK(deleteFile1 == 0);
        CHECK(deleteFile2 == 0);
    }
}