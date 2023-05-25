#include "../doctest.h"

#include "../../src/model/task.h"

TEST_SUITE("Task Class Tests") {
    TEST_CASE("Constructor default memeber value initialisation") {
        Task testTask("Test Task");
        CHECK(testTask.getText() == "Test Task");
        CHECK(testTask.getUrgency() == 0);
        CHECK(testTask.getDueDate() == 0);
        CHECK(testTask.getCompleted() == false);
    }

    TEST_CASE("Comparison operator tests") {
        Task taskA("Test Task A");
        Task taskB("Test Task B");
        
        SUBCASE("Checking unequal tasks") {
            CHECK(taskA != taskB);
        }

        SUBCASE("Checking equal tasks") {
            taskB.setText("Test Task A");
            CHECK(taskA == taskB);
        }
    }
}