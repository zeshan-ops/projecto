/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#ifndef DATA_LOADER_H
#define DATA_LOADER_H

#include <string>
#include "../model/jsonDataInterface.h"

class dataLoader {
    private:
        std::string projectName_;
    public:
        dataLoader(std::string projectName);

        bool dataFileExists();
        void createDataFile();

        Project getProject();
        jsonDataInterface getInterface();
};

#endif