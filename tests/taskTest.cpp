#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/task.h"

TEST_CASE("Task Object Correct Initilisation Check") {
    Task testTask("Test Task", 0, 0);
    std::string taskText = testTask.getTaskText();

    CHECK(taskText.compare("Task Text"));
    CHECK(testTask.getDueDate() == 0);
    CHECK(testTask.getUrgency() == 0);
}

TEST_CASE("Task Text Modifcation Check") { 
    Task testTask("Test Task", 0, 0);
    std::string taskText = testTask.getTaskText();

    testTask.editTaskText("Modified text");
    
    CHECK(taskText.compare("Modified text"));
}