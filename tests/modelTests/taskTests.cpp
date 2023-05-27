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

        taskA.setUrgency(0); taskB.setUrgency(2);
        taskA.setDueDate(1); taskB.setDueDate(2);
        taskA.setCompleted(true); taskB.setCompleted(false);
        
        CHECK(taskA != taskB);

        SUBCASE("Same text") {
            taskA.setText(taskB.getText());
            CHECK(taskA != taskB);

            SUBCASE("Same text and completed") {
                taskA.setCompleted(taskB.getCompleted());
                CHECK(taskA != taskB);

                SUBCASE("Same text and completed and due") {
                    taskA.setDueDate(taskB.getDueDate());
                    CHECK(taskA != taskB);
                }
            }

            SUBCASE("Same text and due") {
                taskA.setDueDate(taskB.getDueDate());
                CHECK(taskA != taskB);

                SUBCASE("Same text and due and urg") {
                    taskA.setUrgency(taskB.getUrgency());
                    CHECK(taskA != taskB);
                }
            }

            SUBCASE("Same text and urg") {
                taskA.setUrgency(taskB.getUrgency());
                CHECK(taskA != taskB);

                SUBCASE("Same text and urg and completed") {
                    taskA.setCompleted(taskB.getCompleted());
                    CHECK(taskA != taskB);
                }
            }
        }

        SUBCASE("Same completed") {
            taskA.setCompleted(taskB.getCompleted());
            CHECK(taskA != taskB);
        }

        SUBCASE("Same due") {
            taskA.setDueDate(taskB.getDueDate());
            CHECK(taskA != taskB);

            SUBCASE("Same due and comp") {
                taskA.setCompleted(taskB.getCompleted());
                CHECK(taskA != taskB);
            }
        }

        SUBCASE("Same urg") {
            taskA.setUrgency(taskB.getUrgency());
            CHECK(taskA != taskB);

            SUBCASE("Same urg and due") {
                taskA.setDueDate(taskB.getDueDate());
                CHECK(taskA != taskB);

                SUBCASE("Same urg and due and comp") {
                    taskA.setCompleted(taskB.getCompleted());
                    CHECK(taskA != taskB);
                }
            }
        }

        SUBCASE("Same text, comp, due and urg") {
            taskA.setText(taskB.getText());
            taskA.setCompleted(taskB.getCompleted());
            taskA.setDueDate(taskB.getDueDate());
            taskA.setUrgency(taskB.getUrgency());
            CHECK(taskA == taskB);
        }
    }
}