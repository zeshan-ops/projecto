/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#ifndef INITIALISER_H
#define INITIALISER_H

#include <string>
#include <filesystem>

class initialiser {
    private:
        std::string focusedProjectName_;
    public:
        initialiser();

        bool dataDirectoryExists();
        bool initialFileExists();

        void createDataDirectory();
        void createInitialFile();

        bool focusedProjectSet();
        std::string getFocusedProjectName();
};

#endif