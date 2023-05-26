#include "jsonDataInterface.h"

/* READING METHODS */
////////////////////////////////////////////////////////////////////////////////
jsonDataInterface :: jsonDataInterface(std::ifstream& inputFile) : 
    allData(json::parse(inputFile)) {
    inputFile.close();
}

////////////////////////////////////////////////////////////////////////////////
json jsonDataInterface :: getData() {
    return allData;
}

////////////////////////////////////////////////////////////////////////////////
json jsonDataInterface :: getJSONProject(std::string projectName) {
    auto jsonProject = std::find_if(allData.begin(), allData.end(), [projectName](const json& x) {
        auto it = x.find("projectName");
        return it != x.end() and it.value() == projectName;
    });

    return *jsonProject;
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
    std::replace_if(allData.begin(), allData.end(), [projectName](const json& x) {
        auto it = x.find("projectName");
        return it != x.end() and it.value() == projectName;
    }, projectData);
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

    editProjectJSON(newData, projectName);
}


////////////////////////////////////////////////////////////////////////////////
void jsonDataInterface :: addNewProjectJSON(const json& projectData) {
    allData.push_back(projectData);
}

////////////////////////////////////////////////////////////////////////////////
void jsonDataInterface :: deleteProject(std::string projectName) {
    allData.erase(std::remove_if(allData.begin(),allData.end(), [projectName](const json& x) {
        auto it = x.find("projectName");
        return it != x.end() and it.value() == projectName;
    }));
}

/* WRITING METHODS */
////////////////////////////////////////////////////////////////////////////////
void jsonDataInterface :: writeData(std::string filename) {
    std::ofstream outputFile(filename);
    std::string outPutData = allData.dump(3);
    outputFile << outPutData;
    outputFile.close();
}