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

    if(projectData["tasks"].size() > 0) {
        for(auto& task : projectData["tasks"]){
            Task t(task["text"]);
            t.setUrgency(task["urgency"]);
            t.setDueDate(task["dueDate"]);
            t.setCompleted(task["completed"]);
            taskList.push_back(t);
        }
    }

    std::vector<Log> logList;

    if(projectData["logs"].size() > 0) {
        for(auto& log : projectData["logs"]){
            Log l(log["text"], log["time"]);
            logList.push_back(l);
        }
    }

    Project p(projectName);

    p.setTasks(taskList);
    p.setLogs(logList);

    return p;
}



/* EDITING METHODS */
////////////////////////////////////////////////////////////////////////////////
void jsonDataInterface :: editProjectJSON(const json& projectData, std::string projectName) {
    int index = getProjectIndex(projectName);
    allData[index] = projectData;
}

////////////////////////////////////////////////////////////////////////////////
void jsonDataInterface :: editProject(const Project& projectData, std::string projectName) {
    json newData;
    newData["projectName"] = projectData.getName();
    
    int index = 0;
    
    for(auto& task : projectData.getTasks()) {
        newData["tasks"][index]["text"] = task.getText();
        newData["tasks"][index]["urgency"] = task.getUrgency();
        newData["tasks"][index]["dueDate"] = task.getDueDate();
        newData["tasks"][index]["completed"] = task.getCompleted();
        ++index;
    }

    index = 0;

    for(auto& logEntry : projectData.getLogs()) {
        newData["logs"][index]["text"] = logEntry.getText();
        newData["logs"][index]["time"] = logEntry.getTime();
        ++index;
    }

    index = getProjectIndex(projectName);
    allData[index] = newData;
}


////////////////////////////////////////////////////////////////////////////////
void jsonDataInterface :: addNewProjectJSON(const json& projectData) {
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
    for(int i = 0; i < allData.size(); i++) {
        if(allData[i]["projectName"] == projectName) {
            return i;
        }
    }
    return 100;
}


