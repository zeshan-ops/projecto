/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#ifndef TASK_H
#define TASK_H

#include <string>
#include <vector>
#include <chrono>
#include "date.h"

using namespace date;
using namespace std::chrono;

class Task {
    private:
        std::string taskText_;
        int urgency_;    // 0, 1, 2, 3 for null, L, M, H urgencies.
        time_point<system_clock, days> dueDate_;            
        bool completed_;

    public:
        Task(std::string taskText);
        Task(std::string taskText, int urgency, time_point<system_clock, days> dueDate);

        void setText(const std::string newText);
        void setUrgency(const int newUrg);
        void setDueDate(const time_point<system_clock, days> newTime);
        void setCompleted(const bool completed);

        std::string getText() const;
        int getUrgency() const;
        time_point<system_clock, days> getDueTimePoint() const;
        bool getCompleted() const;

        // string converter
        std::vector<std::string> stringVector() const;

        bool operator==(const Task& a) const {
            return a.taskText_ == taskText_
                && a.completed_ == completed_
                && a.dueDate_ == dueDate_
                && a.urgency_ == urgency_;
        }

        // Task A < Task B if it has a later date, then a lower urgency
        bool operator<(const Task& a) const {
            if (dueDate_ == a.dueDate_) {
                return urgency_ < a.urgency_;
            } else if (dueDate_ == sys_days{2000_y/1/1}) {
                return dueDate_ < a.dueDate_;
            }
            else {
                return dueDate_ > a.dueDate_;
            }
        }

        // Task A > Task B if it has an older date, then a higher urgency
        bool operator>(const Task& a) const {
            if (dueDate_ == a.dueDate_) {
                return urgency_ > a.urgency_;
            } else if (dueDate_ == sys_days{2000_y/1/1}) {
                return dueDate_ > a.dueDate_;
            } 
            else {
                return dueDate_ < a.dueDate_;
            }
        }
};

#endif