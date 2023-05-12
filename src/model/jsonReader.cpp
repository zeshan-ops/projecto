#include "jsonReader.h"

////////////////////////////////////////////////////////////////////////////////
bool jsonReader :: fileValidater(std::string filename) {
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
json jsonReader :: fileParser(std::string filename) {
    std::ifstream inputFile(filename);

    return json::parse(inputFile);
}

////////////////////////////////////////////////////////////////////////////////
json jsonReader :: projectSelector(const json& jsonData, const std::string projectName) {
    for(auto& element: jsonData) {
        if (element["projectName"] == projectName) {
            return element;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
std::vector<Task> jsonReader :: taskReader(const json& jsonData) {
    json dataTaskList = jsonData["Tasks"];
    
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
std::vector<Log> jsonReader :: logReader(const json& jsonData) {
    json dataLogList = jsonData["Logs"];

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
std::string jsonReader :: nameReader(const json& jsonData) {
    return jsonData["projectName"];
}

////////////////////////////////////////////////////////////////////////////////
/* PUBLIC METHOD */
Project jsonReader :: createProject(std::string filename, const std::string projectName) {
    json allProjects = fileParser(filename);
    json projectData = projectSelector(allProjects, projectName);

    Project project(nameReader(projectData));

    project.setTasks(taskReader(projectData));
    project.setLogs(logReader(projectData));

    return project;
}