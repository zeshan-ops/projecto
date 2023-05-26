#include "../doctest.h"

#include "../../src/model/project.h"

TEST_SUITE("Project Class Tests") {
    TEST_CASE("Constructor behaviour test") {
        Project testProject("Test Project");
        
        CHECK(testProject.getName() == "Test Project");
        CHECK(testProject.getTasks().empty());
        CHECK(testProject.getLogs().empty());
    }

    ///////////////////////////////////////////////////////////////////////////////
    /* Behaviour checks related to tasks of the project */
    TEST_CASE("Adding single task to project") {
        Project testProject("Test Project");

        Task task1("Task 1");
        testProject.addTask(task1);

        CHECK(testProject.getTasks().size() == 1);
        CHECK(testProject.getTask(0) == task1);
        CHECK(testProject.getTasks()[0] == task1);
    }

    TEST_CASE("Editing a single task in a project") {
        Project testProject("Test Project");

        Task task1("Task 1");
        Task task2("Task 2");

        testProject.addTask(task1);
        testProject.editTask(0,task2);
        CHECK(testProject.getTask(0) == task2);
        CHECK(testProject.getTasks().size() == 1);
    }

    TEST_CASE("Deleting a task from a project") {
        Project testProject("Test Project");

        Task task1("Task 1");

        testProject.addTask(task1);
        testProject.deleteTask(0);

        CHECK(testProject.getTasks().size() == 0);
    }

    TEST_CASE("Replacing all tasks in the project") {
        Project testProject("Test Project");

        std::vector<Task> tasks;

        Task task1("Task 1");
        Task task2("Task 2");
        Task task3("Task 3");

        tasks.push_back(task1); tasks.push_back(task2); tasks.push_back(task3);

        testProject.addTask(task1);
        testProject.setTasks(tasks);

        CHECK(testProject.getTasks().size() == 3);
        CHECK(testProject.getTasks() == tasks);
        CHECK(testProject.getTask(0) == task1);
        CHECK(testProject.getTask(1) == task2);
        CHECK(testProject.getTask(2) == task3);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /* Behaviour checks related to logs of a task */
    TEST_CASE("Adding a single log to project") {
        Project testProject("Test Project");

        Log log1("Log 1", 0);
        testProject.addLog(log1);

        CHECK(testProject.getLogs().size() == 1);
        CHECK(testProject.getLog(0) == log1);
        CHECK(testProject.getLogs()[0] == log1);
    }

    TEST_CASE("Deleting a log from a project") {
        Project testProject("Test Project");

        Log log1("Log 1", 0);
        testProject.addLog(log1);
        testProject.deleteLog(0);

        CHECK(testProject.getLogs().size() == 0);
    }

    TEST_CASE("Replacing all logs in project") {
        Project testProject("Test Project");

        Log log1("Log 1", 0);
        Log log2("Log 2", 0);
        Log log3("Log 3", 0);

        std::vector<Log> logs;
        logs.push_back(log1); logs.push_back(log2); logs.push_back(log3);

        testProject.addLog(log1);
        testProject.setLogs(logs);

        CHECK(testProject.getLogs().size() == 3);
        CHECK(testProject.getLogs() == logs);
        CHECK(testProject.getLog(0) == log1);
        CHECK(testProject.getLog(1) == log2);
        CHECK(testProject.getLog(2) == log3);
    }

    ///////////////////////////////////////////////////////////////////////////////
    TEST_CASE("Comparison operator test") {
        Project project1("Test Project 1");
        Project project2("Test Project 2");

        Task task1("Task 1");
        project1.addTask(task1);

        Log log1("Log 1", 0);
        project1.addLog(log1);

        SUBCASE("Checking unequal projects") {
            CHECK(project1 != project2);
        }

        SUBCASE("Checking equal projects") {
            project2.setName("Test Project 1");
            project2.addLog(log1);
            project2.addTask(task1);
            CHECK(project1 == project2);
        }
    }
}