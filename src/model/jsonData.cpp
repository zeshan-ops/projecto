#include "jsonData.h"

/* READING METHODS */
////////////////////////////////////////////////////////////////////////////////
jsonData :: jsonData(std::ifstream& inputFile) {
    allData = json::parse(inputFile);
    inputFile.close();
}

////////////////////////////////////////////////////////////////////////////////
json jsonData :: getData() {
    return allData;
}

////////////////////////////////////////////////////////////////////////////////
json jsonData :: getJSONProject(std::string projectName) {
    return allData[getProjectIndex(projectName)];
}

////////////////////////////////////////////////////////////////////////////////
Project jsonData :: getProject(std::string projectName) {
    json projectData = getJSONProject(projectName);
    
    std::vector<Task> taskList;
    for(auto& task : projectData["tasks"]){
        Task t(task["text"]);
        t.setUrgency(task["urgency"]);
        t.setDueDate(task["dueDate"]);
        t.setCompleted(task["completed"]);
        taskList.push_back(t);
    }

    std::vector<Log> logList;
    for(auto& log : projectData["logs"]){
        Log l(log["text"], log["time"]);
        logList.push_back(l);
    }

    Project p(projectName);

    p.setTasks(taskList);
    p.setLogs(logList);

    return p;
}



/* EDITING METHODS */
////////////////////////////////////////////////////////////////////////////////
void jsonData :: editProject(const json& projectData, std::string projectName) {
    int index = getProjectIndex(projectName);
    allData[index] = projectData;
}

////////////////////////////////////////////////////////////////////////////////
void jsonData :: addNewProject(const json& projectData) {
    allData.push_back(projectData);
}

////////////////////////////////////////////////////////////////////////////////
void jsonData :: deleteProject(std::string projectName) {
    int index = getProjectIndex(projectName);
    allData.erase(allData.begin() + index);
}

/* WRITING METHODS */
////////////////////////////////////////////////////////////////////////////////
void jsonData :: writeData(std::string filename) {
    std::ofstream outputFile(filename);
    std::string outPutData = allData.dump(3);
    outputFile << outPutData;
    outputFile.close();
}

/* UTILITY FUNCTION */
////////////////////////////////////////////////////////////////////////////////
int jsonData :: getProjectIndex(std::string projectName) {
    int index = 0;
    for(auto& project : allData) {
        if(project["projectName"] == projectName) {
            break;
        }
    }
    return index;
}


