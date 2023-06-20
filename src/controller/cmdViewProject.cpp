#include "cmdViewProject.h"

#include <vector>


#include "../view/viewProject.h"
#include "../model/jsonDataInterface.h"
#include "../model/project.h"
#include "../controller/initialiser.h"
#include "../controller/dataLoader.h"

///////////////////////////////////////////////////////////////////////////////
cmdViewProject :: cmdViewProject(std::vector<std::string> args) : args_(args) {};

///////////////////////////////////////////////////////////////////////////////
bool cmdViewProject :: verifyArgs() {
    if (args_.empty()) {
        return true;
    }
    return false;
}

///////////////////////////////////////////////////////////////////////////////
std::string cmdViewProject :: argErrorMessage() {
    return "User input error: viewProject command takes no arguments.";
}

///////////////////////////////////////////////////////////////////////////////
std::string cmdViewProject :: execute() {
    initialiser initer;

    if (initer.focusedProjectSet()) {
        dataLoader loadedData(initer.getFocusedProjectName());
        if (loadedData.projectExists()) {
            Project focusedProject = loadedData.getProject();
            std::vector<std::vector<std::string>> taskList;
            
            int taskID {0};
            for(auto& task : focusedProject.getTasks()) {
                std::vector<std::string> taskStringVector = task.stringVector();
                taskStringVector.insert(taskStringVector.begin(), std::to_string(taskID));
                taskList.push_back(taskStringVector);
                ++taskID;
            }

            std::vector<std::string> lastAction;
            if(!focusedProject.getLogs().empty()) {
                lastAction = focusedProject.getLogs().back().stringVector();
            }

            std::vector<std::string> taskHeaders = {"ID", "Text", "P", "Due Date"};

            viewProject viewHandler(taskList, taskHeaders, lastAction, focusedProject.getName());

            return viewHandler.render();
        } else {
            return "Focused project not found. To set a focused project, use:\nprojecto setFocus <PROJECT NAME>\n";
        }
    } else {
        return "No focused project set. To set a focused project, use:\nprojecto setFocus <PROJECT NAME>\n";
    }
}