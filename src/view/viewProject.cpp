#include "viewProject.h"

///////////////////////////////////////////////////////////////////////////////
viewProject :: viewProject(std::vector<std::vector<std::string>> tList, 
                           std::vector<std::string> tHeaders,
                           std::vector<std::string> last, 
                           std::string name) :
    tasks(tList), taskHeaders(tHeaders), lastAction(last), projectName(name) {};

///////////////////////////////////////////////////////////////////////////////
std::string viewProject :: render() {
    // VIEW HEADER
    std::stringstream composer;

    composer << std::endl;

    composer << txtBold << std::right << txtGreen << std::setw(40+std::ceil(projectName.length()/2))
              << projectName;
    composer << "\n\n";

    // TASKS TABLE
    composer << "TASKS" << txtReset << "\n";

    if(tasks.size() == 0) {
        composer << txtDim << "No outstanding tasks!" << txtReset << "\n";
    } else {
        viewTable taskTable(taskHeaders, tasks);
        std::vector<unsigned int> taskTableWidths = {3, 63, 4, 10};
        composer << taskTable.render(taskTableWidths);
        composer << txtDim << "(" << tasks.size() << " tasks)" << txtReset << "\n";
    }

    composer << "\n";

    // LAST ACTION
    composer << txtGreen << txtBold << "LAST ACTION" << txtReset;
    
    composer << std::endl;

    if(lastAction.size() == 0) {
        composer << txtDim << "No last action!" << txtReset;
    } else {
        composer << txtBold << txtDim << lastAction[0] << txtReset;
    
        composer << "\n";

        composer << viewUtil::wrapText(lastAction[1],80);
    }

    // BLANK LINE SPACER
    composer << "\n";

    return composer.str();
}