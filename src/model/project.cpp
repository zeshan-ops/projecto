#include "project.h"

// constructor
Project :: Project(std::vector<Task> initialTasks, std::vector<Note> initialNotes, std::string initialDescription) {
    tasks = initialTasks;
    notes = initialNotes;
    description = initialDescription;
    lastAction = "No last action written";
}

// data manipulation
void Project :: addTask(Task task) {
    tasks.push_back(task);
}

void Project :: editTask(int taskID, std::string editedText, int editedDate, int editedUrg, bool editedCompletion) {
    tasks[taskID].editTaskText(editedText);
    tasks[taskID].editTaskDueDate(editedDate);
    tasks[taskID].editTaskUrgency(editedUrg);
    tasks[taskID].editCompletion(editedCompletion);
}

void Project :: deleteTask(int taskID) {
    tasks.erase(tasks.begin()+taskID);
}

void Project :: addNote(Note note) {
    notes.push_back(note);
}

void Project :: editNote(int noteID, std::string newNoteText) {
    notes[noteID].editNoteText(newNoteText);
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

// getter methods
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