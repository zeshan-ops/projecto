/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#ifndef TASK_H
#define TASK_H

#include <string>

enum urg { L, M, H };

class Task {
    private:
        std::string taskText;
        urg urgency;
        int dueDate;
        bool completed;

    public:
        // constructor
        Task(std::string text);

        // Setters
        void setText(const std::string newText);
        void setUrgency(const urg newUrg);
        void setDueDate(const int newTime);
        void setCompleted(const bool completion);

        // Getters
        std::string getText() const;
        urg getUrgency() const;
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