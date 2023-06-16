#include "initialiser.h"

#include <filesystem>
#include <iostream>
#include <fstream>
#include <sstream>

///////////////////////////////////////////////////////////////////////////////
initialiser :: initialiser() {
    if (dataDirectoryExists()) {
        if (initialFileExists() && initialFileCorrectFormat()) {
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
            if (initialFileExists()) {
                std::filesystem::remove((std::string)std::getenv("HOME") + "/.project/initial.txt");
            }
            createInitialFile();
            focusedProjectName_ = "FOCUSED PROJECT NOT SET";
        }
    } else {
        createDataDirectory();
        createInitialFile();
        focusedProjectName_ = "FOCUSED PROJECT NOT SET";
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
bool initialiser :: initialFileCorrectFormat() {
    std::string initialFilePath = (std::string)std::getenv("HOME") + "/.projecto/initial.txt";
    std::ifstream initialFile(initialFilePath);

    std::string line;
    bool correctFormat {false};
    bool headerLine {false};

    while (std::getline(initialFile, line)) {
        if (line == "FOCUSED_PROJECT") {
            headerLine = true;
            continue;
        }
        if (headerLine == true) {
            correctFormat = true;
            break;
        }
    }

    return correctFormat;
}

///////////////////////////////////////////////////////////////////////////////
void initialiser :: createDataDirectory() {
    std::string dataDirectoryPath = (std::string)std::getenv("HOME") + "/.projecto";
    std::filesystem::create_directory(dataDirectoryPath);
}

///////////////////////////////////////////////////////////////////////////////
void initialiser :: createInitialFile() {
    std::string initialFilePath = (std::string)std::getenv("HOME") + "/.projecto/initial.txt";

    std::string initialFileHardCode = {"FOCUSED_PROJECT\nFOCUSED PROJECT NOT SET"};
    std::ofstream outputFile(initialFilePath);

    outputFile << initialFileHardCode;
    outputFile.close();
}

///////////////////////////////////////////////////////////////////////////////
bool initialiser :: focusedProjectSet() {
    if (focusedProjectName_ == "FOCUSED PROJECT NOT SET") {
        return false;
    } else {
        return true;
    }
}

///////////////////////////////////////////////////////////////////////////////
std::string initialiser :: getFocusedProjectName() {
    return focusedProjectName_;
}