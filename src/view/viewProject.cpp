#include "viewProject.h"

///////////////////////////////////////////////////////////////////////////////
viewProject :: viewProject(std::vector<std::vector<std::string>> taskList, std::vector<std::string> last, std::string name) :
    tasks(taskList), lastAction(last), projectName(name) {};

///////////////////////////////////////////////////////////////////////////////
void viewProject :: render() {
    std::vector<std::string> taskTableHeaders;
    taskTableHeaders.push_back("ID");
    taskTableHeaders.push_back("Text");
    taskTableHeaders.push_back("Urg");
    taskTableHeaders.push_back("Due Date");

    // VIEW HEADER
    std::cout << std::endl;
    

    std::cout << std::endl;
    std::cout << txtBold << std::right << txtGreen << std::setw(40+std::ceil(projectName.length()/2))
              << projectName;
    std::cout << std::endl;
    std::cout << std::endl;

    // TASKS TABLE
    std::cout << txtGreen << txtBold
              << "TASKS"
              << txtReset;
    std::cout << std::endl;

    if(tasks.size() == 0) {
        std::cout << txtDim << "No outstanding tasks!" << txtReset << std::endl;
    } else {
        viewTable taskTable(taskTableHeaders, tasks);
        std::vector<unsigned int> taskTableWidths = {3, 63, 4, 10};
        taskTable.render(taskTableWidths);
        std::cout << txtDim << "(" << tasks.size() << " tasks)" << txtReset << std::endl;
    }

    std::cout << std::endl;

    // LAST ACTION
    std::cout << txtGreen << txtBold
              << "LAST ACTION"
              << txtReset;
    
    std::cout << std::endl;

    if(lastAction.size() == 0) {
        std::cout << txtDim << "No last action!" << txtReset << std::endl;
    } else {
        std::cout << txtBold << txtDim
                  << lastAction[0]
                  << txtReset;
    
        std::cout << std::endl;

        std::cout << viewUtil::wrapText(lastAction[1],80);
    
        std::cout << std::endl;
    }

    // BLANK LINE SPACER
    std::cout << std::endl;

}