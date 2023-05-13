#include "jsonDataInterface.h"

////////////////////////////////////////////////////////////////////////////////
jsonDataInterface :: jsonDataInterface(const json& masterData) {
    allProjectData = masterData;
}

////////////////////////////////////////////////////////////////////////////////
int jsonDataInterface :: getProjectIndex(std::string projectName) {
    int index = 0;
    for(auto& project : allProjectData) {
        if(project["projectName"] == projectName) {
            break;
        }
    }
    return index;
}

////////////////////////////////////////////////////////////////////////////////
void jsonDataInterface :: editProject(const json& projectData, std::string projectName) {
    int index = getProjectIndex(projectName);
    allProjectData[index] = projectData;
}

////////////////////////////////////////////////////////////////////////////////
void jsonDataInterface :: addNewProject(const json& projectData) {
    allProjectData.push_back(projectData);
}

////////////////////////////////////////////////////////////////////////////////
void jsonDataInterface :: deleteProject(std::string projectName) {
    int index = getProjectIndex(projectName);
    allProjectData.erase(allProjectData.begin() + index);
}

////////////////////////////////////////////////////////////////////////////////
json jsonDataInterface :: getAllData() {
    return allProjectData;
}