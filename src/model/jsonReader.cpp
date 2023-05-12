#include "jsonReader.h"

////////////////////////////////////////////////////////////////////////////////
bool jsonReader :: fileValidater(std::string filename) const {
    std::ifstream inputFile(filename);
    
    // Checking if the file can be opened
    if(!inputFile.is_open()){
        return false;
    } else {
        inputFile.close();
        return true;
    }
}

////////////////////////////////////////////////////////////////////////////////
void jsonReader :: fileParser(std::string filename) {
    std::ifstream inputFile(filename);
    allProjectData = json::parse(inputFile);
}

////////////////////////////////////////////////////////////////////////////////
bool jsonReader :: projectVerifier(const std::string projectName) const {
    for(auto& element : allProjectData) {
        if (element["projectName"] == projectName) {
            return true;
        }
    }

    return false;
}

////////////////////////////////////////////////////////////////////////////////
void jsonReader :: projectSelector(const std::string projectName) {
    int projectIndex = -1;
    for(auto& element: allProjectData) {
        projectIndex += 1;
        if(element["projectName"] == projectName) {
            break;
        }
    }
    selectedProject = allProjectData[projectIndex];
}

////////////////////////////////////////////////////////////////////////////////
std::vector<Task> jsonReader :: taskReader() const {
    json dataTaskList = selectedProject["tasks"];
    
    std::vector<Task> taskList;
    
    for(auto& element : dataTaskList) {
        Task newTask("Initial");
        newTask.setText(element["text"]);
        newTask.setDueDate(element["dueDate"]);
        newTask.setCompleted(element["completed"]);
        newTask.setUrgency(element["urgency"]);

        taskList.push_back(newTask);
    }

    return taskList;
}

////////////////////////////////////////////////////////////////////////////////
std::vector<Log> jsonReader :: logReader() const {
    json dataLogList = selectedProject["logs"];

    std::vector<Log> logList;

    for(auto& element : dataLogList) {
        Log newLog("Initial", 0);
        newLog.setText(element["text"]);
        newLog.setTime(element["time"]);

        logList.push_back(newLog);
    }

    return logList;
}

////////////////////////////////////////////////////////////////////////////////
std::string jsonReader :: nameReader() const {
    return selectedProject["projectName"];
}

////////////////////////////////////////////////////////////////////////////////
/* PUBLIC METHOD */
Project jsonReader :: createProject(std::string filename, const std::string projectName) {
    fileParser(filename);
    projectSelector(projectName);

    Project project("Initial construction");

    project.setName(nameReader());
    project.setTasks(taskReader());
    project.setLogs(logReader());

    return project;
}