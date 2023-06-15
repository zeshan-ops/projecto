#include "dataLoader.h"
#include <filesystem>

///////////////////////////////////////////////////////////////////////////////
dataLoader :: dataLoader (std::string projectName) : projectName_(projectName) {
    if (!dataFileExists()) {
        createDataFile();
    }
}

///////////////////////////////////////////////////////////////////////////////
bool dataLoader :: dataFileExists() {
    return std::filesystem::exists((std::string)std::getenv("HOME") + "/.projecto/data.json");
}

///////////////////////////////////////////////////////////////////////////////
void dataLoader :: createDataFile() {
    std::string dataFilePath = (std::string)std::getenv("HOME") + "/.projecto/data.json";

    std::string dataFileHardCode = {"[]"};
    std::ofstream outputFile(dataFilePath);

    outputFile << dataFileHardCode;
    outputFile.close();
}

///////////////////////////////////////////////////////////////////////////////
Project dataLoader :: getProject() {
    std::string dataFilePath = (std::string)std::getenv("HOME") + "/.projecto/data.json";
    std::ifstream dataFile(dataFilePath);
    jsonDataInterface loadedData(dataFile);
    dataFile.close();
    return loadedData.getProject(projectName_);
}

///////////////////////////////////////////////////////////////////////////////
jsonDataInterface dataLoader :: getInterface() {
    std::string dataFilePath = (std::string)std::getenv("HOME") + "/.projecto/data.json";
    std::ifstream dataFile(dataFilePath);
    jsonDataInterface loadedData(dataFile);
    dataFile.close();
    return loadedData;
}