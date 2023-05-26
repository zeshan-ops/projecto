/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#ifndef JSONDATA_H
#define JSONDATA_H

#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include "json.hpp"
#include "project.h"

using nlohmann::json;

class jsonDataInterface {
    private:
        json allData;
    public:
        // READING METHODS
        jsonDataInterface(std::ifstream& inputFile);

        json getData();
        json getJSONProject(std::string projectName);
        Project getProject(std::string projectName);

        // EDITING METHODS
        void editProjectJSON(const json& projectData, std::string projectName);
        void editProject(const Project& projectData, std::string projectName);
        void addNewProjectJSON(const json& projectData);
        void deleteProject(std::string projectName);

        // WRITING METHODS
        void writeData(std::string filename);
};


#endif