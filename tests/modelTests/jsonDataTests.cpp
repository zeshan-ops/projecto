#include "../doctest.h"

#include "../../src/model/jsonData.h"

TEST_SUITE("JSON Data Object Tests") {
    std::ifstream inputFile("testData1.json");

    jsonData storageData1(inputFile);
    
    TEST_CASE("No modification reading and writing") {
        storageData1.writeData("testData2.json");
        std::ifstream inputFile2("testData2.json");

        jsonData storageData2(inputFile2);

        CHECK(storageData1.getData() == storageData2.getData());
    }

    TEST_CASE("Populating an object") {
        Project storedProject = storageData1.getProject("Test Project 1");

        Project manualProj("Test Project 1");
        std::vector<Task> taskList;

        Task t1("Task 1");
        taskList.push_back(t1);

        Task t2("Task 2");
        t2.setDueDate(1);
        t2.setUrgency(1);
        taskList.push_back(t2);

        Task t3("Task 3");
        t3.setDueDate(2);
        t3.setUrgency(2);
        taskList.push_back(t3);

        Log l1("Log 1", 0);
        Log l2("Log 2", 1);
        Log l3("Log 3", 2);
        std::vector<Log> logList;
        logList.push_back(l1);
        logList.push_back(l2);
        logList.push_back(l3);

        manualProj.setTasks(taskList);
        manualProj.setLogs(logList);

        CHECK(manualProj == storedProject);
    }
}