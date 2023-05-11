/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#ifndef TASK_H
#define TASK_H

#include <string>
#include <chrono>

namespace sc = std::chrono;

enum urg { L, M, H };

class Task {
    private:
        std::string taskText;
        urg urgency;
        sc::time_point<sc::system_clock> dueDate;
        bool completed;

    public:
        // constructor
        Task(std::string text);

        // Setters
        void setText(const std::string newText);
        void setUrgency(const urg newUrg);
        void setDueDate(const sc::time_point<sc::system_clock>& newTime);
        void setCompleted(const bool completion);

        // Getters
        std::string getText() const;
        urg getUrgency() const;
        sc::time_point<sc::system_clock> getDueDate() const;
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