/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#ifndef PROJECT_H
#define PROJECT_H

#include <vector>
#include <string>
#include "task.h"
#include "note.h"

class Project {
    private:
        std::vector<Task> tasks;
        std::vector<Note> notes;
        std::string lastAction;
        std::string description;

    public:
        Project(std::vector<Task> tasks, std::vector<Note> notes, std::string description);
        
        // data manipulation methods
        void addTask(Task task);
        void editTask(int taskID);
        void deleteTask(int taskID);

        void addNote(Note note);
        void editNote(int noteID);
        void deleteNote(int noteID);

        void changeLastAction(std::string lastActionText);

        void editDescription(std::string descriptionText);

        // getter methods
        std::vector<Task> returnTaskList();
        std::vector<Note> returnNoteList();
        std::string returnLastAction();
        std::string returnDescription();
};

#endif