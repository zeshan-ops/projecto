#include "cmdSetFocus.h"
#include "initialiser.h"
#include "dataLoader.h"
#include "../view/ansiMacros.h"
#include <iostream>
#include <fstream>

///////////////////////////////////////////////////////////////////////////////
cmdSetFocus :: cmdSetFocus(std::vector<std::string> args) : args_(args) {};

///////////////////////////////////////////////////////////////////////////////
bool cmdSetFocus :: verifyArgs() {
    if (args_.size() == 2) {
        return true;
    } else {
        return false;
    }
}

///////////////////////////////////////////////////////////////////////////////
std::string cmdSetFocus :: argErrorMessage() {
    return "\nError: too many arugments for command \"setFocus.\"\n This command takes a single argument only: projecto setFocus <string>.\n";
}

///////////////////////////////////////////////////////////////////////////////
std::string cmdSetFocus :: execute() {
    initialiser initer;
    dataLoader loadedData(args_[1]);

    if (!loadedData.projectExists()) {
        return "\nError: \"" + args_[1] + "\" could not be found in data file. \n To see a list of stored projects use: \nprojecto projects\n";
    }

    std::string dataPath = (std::string)std::getenv("HOME") + "/.projecto/initial.txt";
    std::ofstream initFile(dataPath);

    initFile << "FOCUSED_PROJECT\n" + args_[1];

    initFile.close();

    return "\nFocused project has been set to \"" + args_[1] + ".\"\n";
}

