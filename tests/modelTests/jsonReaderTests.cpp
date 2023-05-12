#include "../doctest.h"

#include "../../src/model/jsonReader.h"

TEST_SUITE("jsonReader Unit Tests") {

    TEST_CASE("Correct intialisation") {
        jsonReader dataReader;

        Project fileProject1 = dataReader.createProject("testData1.json", "Test Project 1");
        Project fileProject2 = dataReader.createProject("testData1.json", "Test Project 2");

        Project manualProject1("Test Project 1");

        Task newTask1("Task 1");

        Task newTask2("Task 2");
        newTask2.setUrgency(1);
        newTask2.setDueDate(1);

        Task newTask3("Task 3");
        newTask3.setUrgency(2);
        newTask3.setDueDate(2);

        std::vector<Task> taskList;
        taskList.push_back(newTask1); taskList.push_back(newTask2); taskList.push_back(newTask3);
        manualProject1.setTasks(taskList);

        Log newLog1("Log 1", 0);
        Log newLog2("Log 2", 1);
        Log newLog3("Log 3", 2);
        
        std::vector<Log> logList;
        logList.push_back(newLog1); logList.push_back(newLog2); logList.push_back(newLog3);
        manualProject1.setLogs(logList);

        Project manualProject2 = manualProject1;
        manualProject2.setName("Test Project 2");
        
        CHECK(manualProject1 == fileProject1);
        CHECK(manualProject2 == fileProject2);
    }
}