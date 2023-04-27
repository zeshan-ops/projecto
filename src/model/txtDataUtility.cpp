#include "txtDataUtility.h"

/*
bool validateFile(std::string filename) {
    
}
*/

json fileReader(std::string filename) {
    std::ifstream f(filename);
    json projectData = json::parse(f);
    f.close();

    return projectData;
}

std::vector<Task> readTasks(json projectData) {
    std::vector<Task> storedTasks;

    for(int i = 0; i < projectData["Tasks"].size(); i++) {
        std::string text = projectData["Tasks"][i]["taskText"];
        int taskUrg          = projectData["Tasks"][i]["taskUrg"];
        int taskDue          = projectData["Tasks"][i]["taskDue"];
        bool taskCompletion  = projectData["Tasks"][i]["taskComplete"];

        Task storedTask(text,taskUrg,taskDue);

        storedTasks.push_back(storedTask);
    }

    return storedTasks;
}

std::vector<Note> readNotes(json projectData) {
    std::vector<Note> storedNotes;

    for(int i = 0; i<projectData["Notes"].size(); i++) {
        std::string noteText = projectData["Notes"][i]["noteText"];

        Note storedNote(noteText);
        storedNotes.push_back(storedNote);
    }

    return storedNotes;
}

std::string readDescription(json projectData) {
    return projectData["Description"];
}

std::string readLastAction(json projectData) {
    return projectData["Last Action"];
}