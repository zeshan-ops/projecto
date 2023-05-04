/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#ifndef PROJECT_H
#define PROJECT_H

#include <vector>
#include <string>
#include "task.h"
#include "note.h"
#include "jsonDataUtility.h"

class Project {
    private:
        std::string projectName;
        std::vector<Task> tasks;
        std::vector<Note> notes;
        std::string lastAction;
        std::string description;

    public:
        // Manual constructor
        Project(std::vector<Task> tasks, std::vector<Note> notes, std::string description, std::string projectName);

        // JSON data constructor
        Project(const json& projectData);
        
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
        void editName(std::string newName);

        // getter methods
        std::vector<Task> returnTaskList() const;
        std::vector<Note> returnNoteList() const;
        std::string returnLastAction() const;
        std::string returnDescription() const;
        std::string returnName() const;

        // comparison operator
        bool operator==(const Project& a) const {
            return a.tasks == tasks
                && a.notes == notes
                && a.description == description
                && a.lastAction == lastAction;
        }

        // outputting project as a JSON
        json outputProjectData();
};

#endif