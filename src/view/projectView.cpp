#include "projectView.h"

void showProject(const Project& project) {
    
    std::cout << std::endl; // blank line spacer

    // Task table headers
    std::cout << std::setw(3) << "ID"
              << std::setw(40) << "Task description"
              << std::setw(5) << "Urg"
              << std::setw(5) << "Due"
              << std::endl;

    for(int i = 0; i<project.returnTaskList().size(); i++) {
        std::cout << std::setw(3) << i
                  << std::setw(40) << project.returnTaskList()[i].getTaskText()
                  << std::setw(5) << project.returnTaskList()[i].getUrgency()
                  << std::setw(5) << project.returnTaskList()[i].getDueDate()
                  << std::endl;
    }

    std::cout << std::endl; // blank line spacer
}