/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
    private:
        std::string taskText;
        int urgency;
        int dueDate;
        bool completed;

    public:
        // constructor
        Task(std::string taskText, int urgency, int dueDate);

        // setter functions
        void editTaskText(std::string newTaskText);
        void editTaskUrgency(int newUrgency);
        void editTaskDueDate(int newDueDate);
        void editCompletion(bool completion);

        // getter functions
        std::string getTaskText();
        int getUrgency();
        int getDueDate();

        // check if task is completed
        bool isCompleted();

        // comparison check
        bool operator==(const Task& a) const {
            return a.taskText == taskText
                && a.completed == completed
                && a.dueDate == dueDate
                && a.urgency == urgency;
        }
};

#endif