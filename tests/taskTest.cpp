#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/model/task.h"

TEST_CASE("Task Object Correct Initilisation Check") {
    Task testTask("Initialisation Check", 0, 0);
    std::string taskText = testTask.getTaskText();

    CHECK(taskText.compare("Initialisation Check") == 0);
    CHECK(testTask.getDueDate() == 0);
    CHECK(testTask.getUrgency() == 0);
    CHECK(!testTask.isCompleted());
}

TEST_CASE("Task Attribute Modifcation Check") { 
    Task testTask("Test Task", 0, 0);

    SUBCASE("Task Test Modification") {
        testTask.editTaskText("Modified text");  
        std::string taskText = testTask.getTaskText();
        CHECK(taskText.compare("Modified text") == 0);
    }

    SUBCASE("Task Urgency Modifcation") {
        testTask.editTaskUrgency(1);
        CHECK(testTask.getUrgency() == 1);
    }

    SUBCASE("Task Date Modification") {
        testTask.editTaskDueDate(2);
        CHECK(testTask.getDueDate() == 2);
    }

    SUBCASE("Task Completion Check") {
        testTask.editCompletion(true);
        CHECK(testTask.isCompleted());
    }
}