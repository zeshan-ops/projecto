#include <sstream>
#include <string>
#include <iostream>

#include "../doctest.h"
#include "../../src/controller/cmdViewProject.h"

TEST_SUITE("CMD View Project Class Tests") {
    TEST_CASE("Turning a project into a string") {
        std::stringstream composer;
            
        composer << "\n";
        composer << txtBold << txtGreen << "                                 Test Project 1";
        composer << "\n\n";
        composer << "TASKS" << txtReset << "\n";
        composer 
            << "\033[4m\033[1mID\033[0m \033[4m\033[1mText                                                           \033[0m \033[4m\033[1mP\033[0m \033[4m\033[1mDue Date  \033[0m\n" 
            << "0  Blurg farg jork lorem                                           H 2023-02-02\n"
            << "1  Blurg farg jork lorem                                           H 2023-02-03\n"
            << "2  Blurg farg jork lorem ipsum dolores, truncation galore my...    M 2023-02-03\n"
            << "3  Blurg farg jork lorem                                           L 2023-02-03\n";
        composer << txtDim << "(4 tasks)" << txtReset << "\n";
        composer << "\n";

        composer << txtGreen << txtBold << "LAST ACTION" << txtReset;
        composer << "\n";
        composer << txtBold << txtDim << "2023-06-01 10:42:54" << txtReset;
        composer << "\n";
        composer << "Lorem ipsum dolores, equitat vai sorquet epilin aquila et vac, loresium dolorium\nthe quick brown fox jumper over the lazy dog. Monkeys bashing keyboards would\neventually write the entire works of Shakespeare. Seek the truth, return to the\npath. Etc bon soir mon cherie.";    
        composer << "\n";

        std::string expectedString = composer.str();

        Project testProject("Test Project 1");
        
        Task task1("Blurg farg jork lorem", 3, sys_days{2023_y/2/2});
        Task task2("Blurg farg jork lorem", 3, sys_days{2023_y/2/3});
        Task task3("Blurg farg jork lorem ipsum dolores, truncation galore my dear Watson", 2, sys_days{2023_y/2/3});
        Task task4("Blurg farg jork lorem", 1, sys_days{2023_y/2/3});

        testProject.addTask(task1); testProject.addTask(task2); testProject.addTask(task3);
        testProject.addTask(task4);

        Log log1("Random log text, blah de blah de blah de blah bah humbug said scrooge");
        log1.setTime(sys_days{2020_y/2/1} + 1h + 10min + 34s);
        
        Log log2("This is the second log, it shouldn't print because it wont be the last log in the vector");
        log2.setTime(sys_days{2023_y/4/3} + 18h + 37min + 15s);

        Log log3("Lorem ipsum dolores, equitat vai sorquet epilin aquila et vac, loresium dolorium the quick brown fox jumper over the lazy dog. Monkeys bashing keyboards would eventually write the entire works of Shakespeare. Seek the truth, return to the path. Etc bon soir mon cherie.");
        log3.setTime(sys_days{2023_y/6/1} + 10h + 42min + 54s);

        testProject.addLog(log1); testProject.addLog(log2); testProject.addLog(log3);

        cmdViewProject cmd(testProject);

        CHECK(cmd.execute() == expectedString);
    }
}