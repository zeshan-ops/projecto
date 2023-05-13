/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#ifndef JSON_WRITER_H
#define JSON_WRITER_H

#include<iostream>
#include<fstream>
#include "json.hpp"
#include "project.h"
#include "jsonReader.h"

using nlohmann::json;

class jsonWriter {
    private:
        json allProjectData;
    public:
        jsonWriter(const json& masterData);

        void writeData(std::string filename);
};

#endif