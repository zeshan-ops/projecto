#include "task.h"

////////////////////////////////////////////////////////////////////////////////
Task :: Task(std::string taskText) 
    : taskText_(taskText), urgency_(0), dueDate_(sys_days{2000_y/1/1}), 
      completed_(false) {};

////////////////////////////////////////////////////////////////////////////////
Task :: Task(std::string taskText, int urgency, time_point<system_clock, days> dueDate) 
    : taskText_(taskText), urgency_(urgency), dueDate_(dueDate), 
      completed_(false) {};


////////////////////////////////////////////////////////////////////////////////
/* SETTERS */
void Task :: setText(const std::string text) {
    taskText_ = text;
}

void Task :: setUrgency(const int newUrgency) {
    urgency_ = newUrgency;
}

void Task :: setDueDate(const time_point<system_clock, days> newTime) {
    dueDate_ = newTime;
}

void Task :: setCompleted(const bool completed) {
    completed_ = completed;
}

////////////////////////////////////////////////////////////////////////////////
/* GETTERS */
std::string Task :: getText() const {
    return taskText_;
}

int Task :: getUrgency() const {
    return urgency_;
}

time_point<system_clock, days> Task :: getDueTimePoint() const {
    return dueDate_;
}

bool Task :: getCompleted() const {
    return completed_;
}

std::vector<std::string> Task :: stringVector() const {
    std::vector<std::string> taskStringVector;
    
    taskStringVector.push_back(taskText_);

    switch (urgency_) {
        case 0:
            taskStringVector.push_back("");
            break;
        case 1:
            taskStringVector.push_back("L");
            break;
        case 2:
            taskStringVector.push_back("M");
            break;
        case 3:
            taskStringVector.push_back("H");
            break;
        default:
            taskStringVector.push_back("");
            break;
    }

    if (dueDate_ == sys_days{2000_y/1/1}) {
        taskStringVector.push_back("");
    } else {
        taskStringVector.push_back(format("%F", dueDate_));
    }
    
    if (completed_) {
        taskStringVector.push_back("true");
    } else {
        taskStringVector.push_back("false");
    }

    return taskStringVector;
}