/*

JSON Data Reading Methods

*/

#ifndef JSON_READER_H
#define JSON_READER_H

#include <iostream>
#include <fstream>
#include "json.hpp"
#include "project.h"

using nlohmann::json;

class jsonReader {
    private:
        bool fileValidater(std::string filename);
        json fileParser(std::string filename);
        json projectSelector(const json& jsonData, const std::string projectName);
        std::vector<Task> taskReader(const json& jsonData);
        std::vector<Log> logReader(const json& jsonData);
        std::string nameReader(const json& jsonData);
    public:
        Project createProject(std::string filename, const std::string projectName);
};

#endif