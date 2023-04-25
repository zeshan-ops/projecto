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
}