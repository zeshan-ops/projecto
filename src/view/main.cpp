#include "projectView.h"
#include "../model/txtDataUtility.h"

int main() {
    json projectData = fileReader("view_tester.json");

    std::vector<Task> taskList = readTasks(projectData);
    std::vector<Note> noteList = readNotes(projectData);
    std::string description = readDescription(projectData);
    std::string lastAction = readLastAction(projectData);

    Project project(taskList,noteList,description);
    project.editLastAction(lastAction);

    showProject(project);

    return 0;

}