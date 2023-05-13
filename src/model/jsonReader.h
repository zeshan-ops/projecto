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
        json allProjectData;
        json selectedProject;
    public:
        bool fileValidater(std::string filename) const;
        void fileParser(std::string filename);

        bool projectVerifier(const std::string projectName) const;
        void projectSelector(const std::string projectName);
        
        std::vector<Task> taskReader() const;
        std::vector<Log> logReader() const;
        std::string nameReader() const;

        Project createProject(std::string filename, const std::string projectName);

        json returnAllData() const;
};

#endif