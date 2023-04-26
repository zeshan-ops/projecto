#include "doctest.h"
#include "../src/model/txtDataUtility.h"

TEST_SUITE("Basic data reading test") {
    
    TEST_CASE("File validation") {
        CHECK(validateFile("improperFile.txt") == false);
        CHECK(validateFile("properFile.txt") == true);
    }

    TEST_CASE("Reading tasks") {
        std::vector<Task> testTasks;
        Task task1("Task 1", 0, 0);
        Task task2("Task 2", 1, 2);
        Task task3("Task 3", 3, 20);

        testTasks.push_back(task1);
        testTasks.push_back(task2);
        testTasks.push_back(task3);

        CHECK(readTasks("testData.txt") == testTasks);
    }

    TEST_CASE("Reading notes") {
        std::vector<Note> testNotes;
        Note note1("Note 1");
        Note note2("Note 2");
        Note note3("Note 3");

        testNotes.push_back(note1);
        testNotes.push_back(note2);
        testNotes.push_back(note3);

        CHECK(readNotes("testData.txt") == testNotes);
    }

    TEST_CASE("Reading description and last action") {
        std::string description = "A test project for unit testing";
        std::string lastAction = "The last thing I did was create this unit test file";

        CHECK(readDescription("testData.txt") == description);
        CHECK(readLastAction("testData.txt") == lastAction);
    }
}