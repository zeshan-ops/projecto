/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#ifndef JSONDATA_H
#define JSONDATA_H

#include <string>
#include <iostream>
#include <fstream>
#include "json.hpp"
#include "project.h"

using nlohmann::json;

class jsonData {
    private:
        json allData;
    public:
        // READING METHODS
        jsonData(std::ifstream& inputFile);

        json getData();
        json getProject(std::string projectName);

        // EDITING METHODS
        void editProject(const json& projectData, std::string projectName);
        void addNewProject(const json& projectData);
        void deleteProject(std::string projectName);

        // WRITING METHODS
        void writeData(std::string filename);

        // UTILITY FUNCTION
        int getProjectIndex(std::string projectName);
};


#endif