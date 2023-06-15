#include "../doctest.h"

#include "../../src/model/task.h"

TEST_SUITE("Task Class Tests") {
    TEST_CASE("Constructor default memeber value initialisation") {
        Task testTask("Test Task");
        CHECK(testTask.getText() == "Test Task");
        CHECK(testTask.getUrgency() == 0);
        CHECK(testTask.getDueTimePoint() == sys_days{2000_y/1/1});
        CHECK(testTask.getCompleted() == false);
    }

    TEST_CASE("Full constructor initialisation") {
        Task testTask("Test Task", 2, sys_days{2020_y/1/1});
        CHECK(testTask.getText() == "Test Task");
        CHECK(testTask.getUrgency() == 2);
        CHECK(testTask.getDueTimePoint() == sys_days{2020_y/1/1});
        CHECK(testTask.getCompleted() == false);
    }

    TEST_CASE("String converter") {
        Task testTask("Test Task", 0, sys_days{2020_y/1/1});
        std::vector<std::string> stringVectorTask = testTask.stringVector();
        CHECK(stringVectorTask.size() == 4);
        CHECK(stringVectorTask[0] == "Test Task");
        CHECK(stringVectorTask[2] == format("%F", floor<days>(sys_days{2020_y/1/1})));
        CHECK(stringVectorTask[3] == "false");
        CHECK(stringVectorTask[1] == "");
        
        testTask.setUrgency(1);
        stringVectorTask = testTask.stringVector();
        CHECK(stringVectorTask[1] == "L");

        testTask.setUrgency(2);
        stringVectorTask = testTask.stringVector();
        CHECK(stringVectorTask[1] == "M");

        testTask.setUrgency(3);
        stringVectorTask = testTask.stringVector();
        CHECK(stringVectorTask[1] == "H");

        Task testTask2("Minimal test task");
        testTask2.setCompleted(true);
        stringVectorTask = testTask2.stringVector();
        CHECK(stringVectorTask[1] == "");
        CHECK(stringVectorTask[2] == "");
        CHECK(stringVectorTask[3] == "true");
    }

    TEST_CASE("Equality operator tests") {
        Task taskA("Test Task A");
        Task taskB("Test Task B");

        taskA.setUrgency(0); 
        taskA.setCompleted(true); 
        taskA.setDueDate(sys_days{2023_y/1/1});
        
        taskB.setUrgency(2);
        taskB.setCompleted(false);
        taskB.setDueDate(sys_days{2023_y/1/2});

        
        CHECK(taskA != taskB);

        SUBCASE("Same text") {
            taskA.setText(taskB.getText());
            CHECK(taskA != taskB);

            SUBCASE("Same text and completed") {
                taskA.setCompleted(taskB.getCompleted());
                CHECK(taskA != taskB);

                SUBCASE("Same text and completed and due") {
                    taskA.setDueDate(taskB.getDueTimePoint());
                    CHECK(taskA != taskB);
                }
            }

            SUBCASE("Same text and due") {
                taskA.setDueDate(taskB.getDueTimePoint());
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
            taskA.setDueDate(taskB.getDueTimePoint());
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
                taskA.setDueDate(taskB.getDueTimePoint());
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
            taskA.setDueDate(taskB.getDueTimePoint());
            taskA.setUrgency(taskB.getUrgency());
            CHECK(taskA == taskB);
        }
    }

    TEST_CASE("Less than operator tests") {
        Task taskA("Test Task A");
        Task taskB("Test Task B");

        taskA.setUrgency(0); 
        taskA.setCompleted(true); 
        taskA.setDueDate(sys_days{2023_y/1/1});
        
        taskB.setUrgency(2);
        taskB.setCompleted(false);
        taskB.setDueDate(sys_days{2023_y/1/2});

        SUBCASE("Due date less, urgency less") {
            CHECK(taskB < taskA);
        }

        SUBCASE("Due date less, urgency equal") {
            taskB.setUrgency(taskA.getUrgency());
            CHECK(taskB < taskA);
        }

        SUBCASE("Due date equal, urgency less") {
            taskB.setDueDate(taskA.getDueTimePoint());
            CHECK(taskA < taskB);
        }
    }
}