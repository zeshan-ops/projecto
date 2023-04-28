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
        void addTask(const Task& task);
        void editTask(int taskID, std::string editedText, int editedDate, int editedUrg, 
                      bool editedCompletion);
        void deleteTask(int taskID);

        void addNote(const Note& note);
        void editNote(int noteID, std::string newNoteText);
        void deleteNote(int noteID);

        void editLastAction(std::string lastActionText);

        void editDescription(std::string descriptionText);

        // getter methods
        const std::vector<Task> returnTaskList();
        const std::vector<Note> returnNoteList();
        const std::string returnLastAction();
        const std::string returnDescription();
};

#endif