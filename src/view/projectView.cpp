#include "projectView.h"

void showProject(const Project& project) {
    
    std::cout << std::endl; // blank line spacer

    // Project Name
    std::cout << txtBold << txtBlue << "PROJECT: " << txtReset
              << txtItalic << std::setw(10) << project.returnName() 
              << txtReset
              << std::endl;

    std::cout << std::endl; // blank line spacer

    // Task table header
    std::cout << txtBold << txtGreen << std::setw(80) << "TASKS" << txtReset << std::endl;
    std::cout << txtUnderline 
              << std::setw(3) << "ID"
              << std::setw(40) << "Description"
              << std::setw(5) << "Urg"
              << std::setw(5) << "Due" 
              << txtReset
              << std::endl;

    for(int i = 0; i<project.returnTaskList().size(); i++) {
        std::cout << std::setw(3) << i
                  << std::setw(40) << project.returnTaskList()[i].getTaskText()
                  << std::setw(5) << project.returnTaskList()[i].getUrgency()
                  << std::setw(5) << project.returnTaskList()[i].getDueDate()
                  << std::endl;
    }

    std::cout << std::endl; // blank line spacer

    // Note table header
    std::cout << txtBold << txtGreen << std::setw(80) << "NOTES" << txtReset << std::endl;
    std::cout << txtUnderline
              << std::setw(3) << "ID"
              << std::setw(40) << "Note text"
              << txtReset
              << std::endl;

    for(int i = 0; i<project.returnNoteList().size(); i++) {
        std::cout << std::setw(3) << i
                  << std::setw(40) << project.returnNoteList()[i].getNoteNext()
                  << std::endl;
    }

    std::cout << std::endl; // blank line spacer
}