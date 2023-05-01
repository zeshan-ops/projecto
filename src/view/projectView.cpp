#include "projectView.h"

void showProject(const Project& project) {

    int taskColumnWidth = 62;
    
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
              << std::setw(taskColumnWidth) << "Description"
              << std::setw(4) << "Urg"
              << std::setw(11) << "Due" 
              << txtReset
              << std::endl;

    for(int i = 0; i<project.returnTaskList().size(); i++) {
        std::cout << std::setw(3) << i
                  << std::setw(taskColumnWidth) << truncateText(project.returnTaskList()[i].getTaskText(),taskColumnWidth)
                  << std::setw(4) << project.returnTaskList()[i].getUrgency()
                  << std::setw(11) << project.returnTaskList()[i].getDueDate()
                  << std::endl;
    }

    std::cout << std::endl; // blank line spacer

    // Note table header
    std::cout << txtBold << txtGreen << std::setw(80) << "NOTES" << txtReset << std::endl;
    std::cout << txtUnderline
              << std::setw(3) << "ID"
              << std::setw(77) << "Note text"
              << txtReset
              << std::endl;

    for(int i = 0; i<project.returnNoteList().size(); i++) {
        std::cout << std::setw(3) << i
                  << std::setw(77) << project.returnNoteList()[i].getNoteNext()
                  << std::endl;
    }

    std::cout << std::endl; // blank line spacer
}