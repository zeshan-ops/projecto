#include "doctest.h"
#include "../src/model/project.h"

TEST_SUITE("Project Object Tests") {
    TEST_CASE("Default intialisation") {
        std::vector<Task> testTaskVector;
        Task testTask("Test Task", 0, 0);
        testTaskVector.push_back(testTask);

        std::vector<Note> testNoteVector;
        Note testNote("Test Note");
        testNoteVector.push_back(testNote);

        std::string testDescription = "Test Description";

        Project testProject(testTaskVector, testNoteVector, testDescription);
        
        SUBCASE("Correct initialisation test") {
            CHECK(testProject.returnTaskList() == testTaskVector);
            CHECK(testProject.returnNoteList() == testNoteVector);
            CHECK(testProject.returnDescription() == testDescription);
            CHECK(testProject.returnLastAction() == "No last action written");
        }
    }
    TEST_CASE("Data Manipulation") {
        std::vector<Task> testTaskVector;
        Task testTask("Test Task", 0, 0);
        testTaskVector.push_back(testTask);

        std::vector<Note> testNoteVector;
        Note testNote("Test Note");
        testNoteVector.push_back(testNote);

        std::string testDescription = "Test Description";

        Project testProject(testTaskVector, testNoteVector, testDescription);

        SUBCASE("Adding a task") {
            Task newTask("New task", 0, 0);
            testTaskVector.push_back(newTask);
            testProject.addTask(newTask);
            CHECK(testProject.returnTaskList() == testTaskVector);
        }

        SUBCASE("Deleting a task") {
            testProject.deleteTask(0);
            CHECK(testProject.returnTaskList().size() == 0);
        }

        SUBCASE("Editing a task") {
            testProject.editTask(0, "Edited task", 20, 10, true);
            testTaskVector[0].editTaskText("Edited task");
            testTaskVector[0].editTaskDueDate(20);
            testTaskVector[0].editTaskUrgency(10);
            testTaskVector[0].editCompletion(true);
            CHECK(testProject.returnTaskList() == testTaskVector);
        }
    }
}