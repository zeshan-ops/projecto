/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
    private:
        std::string taskText;
        int urgency;            // 0, 1, 2, 3 for null, L, M, H urgencies.
        int dueDate;            // 0 is no date.
        bool completed = false;

    public:
        // constructor
        Task(std::string text);

        // Setters
        void setText(const std::string newText);
        void setUrgency(const int newUrg);
        void setDueDate(const int newTime);
        void setCompleted(const bool completion);

        // Getters
        std::string getText() const;
        int getUrgency() const;
        int getDueDate() const;
        bool getCompleted() const;

        // comparison overload
        bool operator==(const Task& a) const {
            return a.taskText == taskText
                && a.completed == completed
                && a.dueDate == dueDate
                && a.urgency == urgency;
        }
};

#endif