#include "project.h"

////////////////////////////////////////////////////////////////////////////////
/* CONSTRUCTORS */
Project :: Project(std::vector<Task> initialTasks, std::vector<Note> initialNotes, 
                   std::string initialDescription, std::string initialName) {
    tasks = initialTasks;
    notes = initialNotes;
    description = initialDescription;
    lastAction = "No last action written";
    projectName = initialName;
}

Project :: Project(const json& projectData) {
    tasks = readTasks(projectData);
    notes = readNotes(projectData);
    description = readDescription(projectData);
    lastAction = readLastAction(projectData);
    projectName = readName(projectData);
}

////////////////////////////////////////////////////////////////////////////////
/* DATA MANIPULATION (SETTERS & EDITORS) */
void Project :: addTask(const Task& task) {
    tasks.push_back(task);
}

void Project :: editTask(int taskID, const Task& task) {
    tasks[taskID] = task;
}

void Project :: deleteTask(int taskID) {
    tasks.erase(tasks.begin()+taskID);
}

void Project :: addNote(const Note& note) {
    notes.push_back(note);
}

void Project :: editNote(int noteID, const Note& note) {
    notes[noteID] = note;
}

void Project :: deleteNote(int noteID) {
    notes.erase(notes.begin()+noteID);
}

void Project :: editLastAction(std::string lastActionText) {
    lastAction = lastActionText;
}

void Project :: editDescription(std::string descriptionText) {
    description = descriptionText;
}

void Project :: editName(std::string newName) {
    projectName = newName;
}

////////////////////////////////////////////////////////////////////////////////
/* GETTERS */
std::vector<Task> Project :: returnTaskList() const {
    return tasks;
}

std::vector<Note> Project :: returnNoteList() const {
    return notes;
}

std::string Project :: returnDescription() const {
    return description;
}

std::string Project :: returnLastAction() const {
    return lastAction;
}

std::string Project :: returnName() const {
    return projectName;
}

json Project :: outputProjectData() {
    json outputProject;
    outputProject["Project Name"] = projectName;
    outputProject["Description"] = description;
    outputProject["Last Action"] = lastAction;
    
    for(int i = 0; i < tasks.size(); i++) {
        outputProject["Tasks"][i]["taskText"] = tasks[i].getTaskText();
        outputProject["Tasks"][i]["taskUrg"] = tasks[i].getUrgency();
        outputProject["Tasks"][i]["taskDue"] = tasks[i].getDueDate();
        outputProject["Tasks"][i]["taskComplete"] = tasks[i].isCompleted();
    }

    for(int i =0; i<notes.size(); i++) {
        outputProject["Notes"][i]["noteText"] = notes[i].getNoteNext();
    }
    
    return outputProject;
}