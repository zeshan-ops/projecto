#include "projectView.h"

void showProjectView(const Project& project) {

    int taskColumnWidth = 62;
    int noteColumnWidth = 62;
    
    std::cout << std::endl; // blank line spacer

    // Project Name
    std::cout << txtBold << txtYellow << txtUnderline "PROJECT:" << txtReset << " "
              << txtItalic << std::setw(10) << project.returnName() 
              << txtReset
              << std::endl;
    
    // Project Description
    std::cout << txtItalic << txtDim << project.returnDescription()
              << txtReset
              << std::endl;
    

    std::cout << std::endl; // blank line spacer

    // Task table header
    std::cout << txtBold << txtGreen << std::setw(80) << std::left << "TASKS" << txtReset << std::endl;
    std::cout << txtUnderline 
              << std::setw(2) << "ID"
              << txtReset << std::setw(1) << " "
              << txtUnderline
              << std::setw(taskColumnWidth) << "Description"
              << txtReset << std::setw(1) << " "
              << txtUnderline
              << std::setw(4) << "Urg"
              << txtReset << std::setw(1) << " "
              << txtUnderline
              << std::setw(11) << "Due" 
              << txtReset
              << std::endl;

    for(int i = 0; i<project.returnTaskList().size(); i++) {
        std::cout << std::setw(2) << i
                  << std::setw(1) << " "
                  << std::setw(taskColumnWidth) << truncateText(project.returnTaskList()[i].getTaskText(),taskColumnWidth)
                  << std::setw(1) << " "
                  << std::setw(4) << project.returnTaskList()[i].getUrgency()
                  << std::setw(1) << " "
                  << std::setw(11) << project.returnTaskList()[i].getDueDate()
                  << std::endl;
    }

    std::cout << std::endl; // blank line spacer

    // Note table header
    std::cout << txtBold << txtGreen << std::setw(80) << "NOTES" << txtReset << std::endl;
    std::cout << txtUnderline
              << std::setw(2) << "ID"
              << txtReset << std::setw(1) << " "
              << txtUnderline
              << std::setw(noteColumnWidth) << "Title"
              << txtReset
              << std::endl;

    for(int i = 0; i<project.returnNoteList().size(); i++) {
        std::cout << std::setw(2) << i
                  << std::setw(1) << " "
                  << std::setw(77) << truncateText(project.returnNoteList()[i].getNoteNext(), noteColumnWidth)
                  << std::endl;
    }

    std::cout << std::endl; // blank line spacer

    // Last action header
    std::cout << txtBold << txtGreen << std::setw(80) << "LAST ACTION"
              << txtReset
              << std::endl;
    
    std::cout << std::setw(80) << project.returnLastAction()
              << std::endl;

    std::cout << std::endl; //blank line spacer
}