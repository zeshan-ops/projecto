#include "jsonReader.h"

////////////////////////////////////////////////////////////////////////////////
jsonReader :: jsonReader(std::string filename) {
    std::ifstream inputFile(filename);
    allProjectData = json::parse(inputFile);
    inputFile.close();
}

////////////////////////////////////////////////////////////////////////////////
json jsonReader :: getAllData() {
    return allProjectData;
}

////////////////////////////////////////////////////////////////////////////////
json jsonReader :: getProjectData(std::string projectName) {
    return allProjectData[getProjectIndex(projectName)];
}

////////////////////////////////////////////////////////////////////////////////
int jsonReader :: getProjectIndex(std::string projectName) {
    int index = 0;
    for(auto& project : allProjectData) {
        if(project["projectName"] == projectName) {
            break;
        }
    }
    return index;
}

