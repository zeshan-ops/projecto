/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#ifndef JSON_DATA_INTERFACE_H
#define JSON_DATA_INTERFACE_H

#include "json.hpp"
#include <string>

using nlohmann::json;

class jsonDataInterface {
    private:
        json allProjectData;
    public:
        jsonDataInterface(const json& masterData);

        int getProjectIndex(std::string projectName);

        void editProject(const json& projectData, std::string projectName);
        void addNewProject(const json& projectData);
        void deleteProject(std::string projectName);

        json getAllData();

};

#endif