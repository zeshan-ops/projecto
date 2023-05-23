#include "jsonDataInterface.h"

/* READING METHODS */
////////////////////////////////////////////////////////////////////////////////
jsonDataInterface :: jsonDataInterface(std::ifstream& inputFile) {
    allData = json::parse(inputFile);
    inputFile.close();
}

////////////////////////////////////////////////////////////////////////////////
json jsonDataInterface :: getData() {
    return allData;
}

////////////////////////////////////////////////////////////////////////////////
json jsonDataInterface :: getJSONProject(std::string projectName) {
    return allData[getProjectIndex(projectName)];
}

////////////////////////////////////////////////////////////////////////////////
Project jsonDataInterface :: getProject(std::string projectName) {
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
void jsonDataInterface :: editProject(const json& projectData, std::string projectName) {
    int index = getProjectIndex(projectName);
    allData[index] = projectData;
}

////////////////////////////////////////////////////////////////////////////////
void jsonDataInterface :: addNewProject(const json& projectData) {
    allData.push_back(projectData);
}

////////////////////////////////////////////////////////////////////////////////
void jsonDataInterface :: deleteProject(std::string projectName) {
    int index = getProjectIndex(projectName);
    allData.erase(allData.begin() + index);
}

/* WRITING METHODS */
////////////////////////////////////////////////////////////////////////////////
void jsonDataInterface :: writeData(std::string filename) {
    std::ofstream outputFile(filename);
    std::string outPutData = allData.dump(3);
    outputFile << outPutData;
    outputFile.close();
}

/* UTILITY FUNCTION */
////////////////////////////////////////////////////////////////////////////////
int jsonDataInterface :: getProjectIndex(std::string projectName) {
    int index = 0;
    for(auto& project : allData) {
        if(project["projectName"] == projectName) {
            break;
        }
    }
    return index;
}


