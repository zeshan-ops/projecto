#include "cmdRoutineA.h"

////////////////////////////////////////////////////////////////////////////////
/* Initialise*/
cmdRoutineA :: cmdRoutineA(std::ifstream& inputFile, std::string projectName) :
               storageData(loadData(inputFile)), 
               focusedProject(loadProject(projectName)) 
               {};

////////////////////////////////////////////////////////////////////////////////
jsonDataInterface cmdRoutineA :: loadData(std::ifstream& inputFile) {
    jsonDataInterface jdi(inputFile);
    return jdi;
}

////////////////////////////////////////////////////////////////////////////////
Project cmdRoutineA :: loadProject(std::string projectName) {
    return storageData.getProject(projectName);
}

