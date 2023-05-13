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
    public:
        jsonReader(std::string filename);

        json getAllData();
        json getProjectData(std::string projectName);

        // utility function
        int getProjectIndex(std::string projectName);
};

#endif