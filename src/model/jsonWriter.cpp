#include "jsonWriter.h"

////////////////////////////////////////////////////////////////////////////////
jsonWriter :: jsonWriter(const json& masterData) {
    allProjectData = masterData;
}

void jsonWriter :: writeData(std::string filename) {
    std::ofstream outputFile(filename);
    std::string outPutData = allProjectData.dump(3);
    outputFile << outPutData;
}