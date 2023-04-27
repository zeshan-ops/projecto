#include "txtDataUtility.h"

/*
bool validateFile(std::string filename) {
    
}
*/

json fileReader(std::string filename) {
    std::ifstream file(filename);
    json projectData = json::parse(file);
    file.close();

    return projectData;
}

std::vector<Task> readTasks(json projectData);
std::vector<Note> readNotes(json projectData);
std::string readDescription(json projectData);
std::string readLastAction(json projectData);