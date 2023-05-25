/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#ifndef CMD_ROUTINE_A
#define CMD_ROUTINE_A

#include "../model/jsonDataInterface.h"

class cmdRoutineA {
    protected:
        jsonDataInterface storageData;
        Project focusedProject;
        
        jsonDataInterface loadData(std::ifstream& inputFile);
        Project loadProject(std::string projectName);
    public:
        cmdRoutineA(std::ifstream& inputFile, std::string projectName);        
};

#endif
