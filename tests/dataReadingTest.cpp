#include "doctest.h"
#include "../src/model/txtDataUtility.h"

TEST_SUITE("Basic data reading test") {
    
    /*
    TEST_CASE("File validation") {
        CHECK(validateFile("improperFile.txt") == false);
        CHECK(validateFile("testProjectData1.txt") == true);
    }
    */

    TEST_CASE("Reading json data") {

        json projectData = fileReader("testProjectData1.json");

        SUBCASE("Reading task data") {
            std::vector<Task> testTasks;
            Task task1("Task 1", 0, 0);
            Task task2("Task 2", 0, 0);
            Task task3("Task 3", 0, 0);

            testTasks.push_back(task1);
            testTasks.push_back(task2);
            testTasks.push_back(task3);

            std::vector<Task> projectTasks = readTasks(projectData);

            CHECK(projectTasks == testTasks);
        }

        SUBCASE("Reading notes") {
            std::vector<Note> testNotes;
            Note note1("Note 1");
            Note note2("Note 2");

            testNotes.push_back(note1);
            testNotes.push_back(note2);

            std::vector<Note> projectNotes = readNotes(projectData);

            CHECK(projectNotes == testNotes);
        }

        SUBCASE("Reading description and last action") {
            std::string description = "A test project for unit testing";
            std::string lastAction = "The last thing I did was create this unit test file";

            CHECK(readDescription(projectData) == description);
            CHECK(readLastAction(projectData) == lastAction);
        }
    }
}