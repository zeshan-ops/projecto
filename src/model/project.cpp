#include "project.h"

// constructor
Project :: Project(std::vector<Task> initialTasks, std::vector<Note> initialNotes, std::string initialDescription) {
    tasks = initialTasks;
    notes = initialNotes;
    description = initialDescription;
    lastAction = "No last action written";
}

//
// getter methods
//
std::vector<Task> Project :: returnTaskList() {
    return tasks;
}

std::vector<Note> Project :: returnNoteList() {
    return notes;
}

std::string Project :: returnDescription() {
    return description;
}

std::string Project :: returnLastAction() {
    return lastAction;
}
//
// data manipulation
//
void Project :: addTask(Task task) {
    tasks.push_back(task);
}

void Project :: deleteTask(int taskID) {
    tasks.erase(tasks.begin()+taskID-1);
}