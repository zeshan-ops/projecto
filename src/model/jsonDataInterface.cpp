#include "jsonDataInterface.h"

/* READING METHODS */
////////////////////////////////////////////////////////////////////////////////
jsonDataInterface :: jsonDataInterface(std::istream& inputFile) : 
    allData(json::parse(inputFile)) {};

////////////////////////////////////////////////////////////////////////////////
bool jsonDataInterface :: projectExists(std::string projectName) {
    auto jsonProject = std::find_if(allData.begin(), allData.end(), [projectName](const json& x) {
        auto it = x.find("projectName");
        return it != x.end() and it.value() == projectName;
    });

    if (jsonProject != allData.end()) {
        return true;
    } else {
        return false;
    }
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

    if(!projectData["tasks"].empty()) {
        for(auto& task : projectData["tasks"]){
            time_point<system_clock, days> tp = floor<days>(modelUtil :: stringToTimePoint(task["dueDate"]));

            Task t(task["text"], task["urgency"], tp);
            t.setCompleted(task["completed"]);

            taskList.push_back(t);
        }
    }

    std::vector<Log> logList;

    if(!projectData["logs"].empty()) {
        for(auto& log : projectData["logs"]){
            Log l(log["text"]);
            l.setTime(floor<seconds>(modelUtil :: stringToTimePoint(log["time"])));
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
    
    unsigned int index = 0;
    
    for(auto& task : projectData.getTasks()) {
        newData["tasks"][index]["text"] = task.getText();
        newData["tasks"][index]["urgency"] = task.getUrgency();
        newData["tasks"][index]["dueDate"] = format("%F %T", task.getDueTimePoint());
        newData["tasks"][index]["completed"] = task.getCompleted();
        ++index;
    }

    index = 0;

    for(auto& logEntry : projectData.getLogs()) {
        newData["logs"][index]["text"] = logEntry.getText();
        newData["logs"][index]["time"] = format("%F %T",logEntry.getTimePoint());
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