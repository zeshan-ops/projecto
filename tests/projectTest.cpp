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

    TEST_CASE("Individual task manipulation") {
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

    TEST_CASE("Individual note manipulation") {
        std::vector<Task> testTaskVector;
        Task testTask("Test Task", 0, 0);
        testTaskVector.push_back(testTask);

        std::vector<Note> testNoteVector;
        Note testNote("Test Note");
        testNoteVector.push_back(testNote);

        std::string testDescription = "Test Description";

        Project testProject(testTaskVector, testNoteVector, testDescription);

        SUBCASE("Adding a note") {
            Note newNote("New note text");
            testNoteVector.push_back(newNote);
            testProject.addNote(newNote);
            CHECK(testProject.returnNoteList() == testNoteVector);
        }

        SUBCASE("Deleting a note") {
            testProject.deleteNote(0);
            CHECK(testProject.returnNoteList().size() == 0);
        }

        SUBCASE("Editing a note") {
            testProject.editNote(0, "Edited note");
            testNoteVector[0].editNoteText("Edited note");
            CHECK(testProject.returnNoteList() == testNoteVector);
        }
    }

    TEST_CASE("Last action and description modification") {
        std::vector<Task> testTaskVector;
        Task testTask("Test Task", 0, 0);
        testTaskVector.push_back(testTask);

        std::vector<Note> testNoteVector;
        Note testNote("Test Note");
        testNoteVector.push_back(testNote);

        std::string testDescription = "Test Description";

        Project testProject(testTaskVector, testNoteVector, testDescription);

        SUBCASE("Editing last action") {
            testProject.editLastAction("Changed last action");
            CHECK(testProject.returnLastAction() == "Changed last action");
        }

        SUBCASE("Editing description") {
            testProject.editDescription("Changed description");
            CHECK(testProject.returnDescription() == "Changed description");
        }
    }
}