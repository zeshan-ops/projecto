#include "initialiser.h"

#include <filesystem>
#include <iostream>
#include <fstream>
#include <sstream>

///////////////////////////////////////////////////////////////////////////////
initialiser :: initialiser() {
    if (dataDirectoryExists()) {
        if (initialFileExists()) {
            std::string initialFilePath = (std::string)std::getenv("HOME") + "/.projecto/initial.txt";
            std::ifstream initialFile(initialFilePath);

            std::string line;
            bool focusedProjectLine {false};

            while (std::getline(initialFile, line)) {
                if (focusedProjectLine) {
                    break;
                }
                if (line == "FOCUSED_PROJECT") {
                    focusedProjectLine = true;
                }
            }

            focusedProjectName_ = line;
        } else {
            createInitialFile();
            focusedProjectName_ = " ";
        }
    } else {
        createDataDirectory();
        createInitialFile();
        focusedProjectName_ = " ";
    }
}

///////////////////////////////////////////////////////////////////////////////
bool initialiser :: dataDirectoryExists() {
    return std::filesystem::exists(std::string(std::getenv("HOME")) + "/.projecto");
}

///////////////////////////////////////////////////////////////////////////////
bool initialiser :: initialFileExists() {
    return std::filesystem::exists((std::string)std::getenv("HOME") + "/.projecto/initial.txt");
}

///////////////////////////////////////////////////////////////////////////////
void initialiser :: createDataDirectory() {
    std::string dataDirectoryPath = (std::string)std::getenv("HOME") + "/.projecto";
    std::filesystem::create_directory(dataDirectoryPath);
}

///////////////////////////////////////////////////////////////////////////////
void initialiser :: createInitialFile() {
    std::string initialFilePath = (std::string)std::getenv("HOME") + "/.projecto/initial.txt";

    std::string initialFileHardCode = {"FOCUSED_PROJECT\n "};
    std::ofstream outputFile(initialFilePath);

    outputFile << initialFileHardCode;
    outputFile.close();
}

///////////////////////////////////////////////////////////////////////////////
bool initialiser :: focusedProjectSet() {
    if (focusedProjectName_ == " ") {
        return false;
    } else {
        return true;
    }
}

///////////////////////////////////////////////////////////////////////////////
std::string initialiser :: getFocusedProjectName() {
    return focusedProjectName_;
}