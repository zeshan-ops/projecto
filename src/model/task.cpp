#include "task.h"

Task :: Task(std::string text) {
    taskText = text;
}

////////////////////////////////////////////////////////////////////////////////
/* SETTERS */
void Task :: setText(const std::string text) {
    taskText = text;
}

void Task :: setUrgency(const urg newUrgency) {
    urgency = newUrgency;
}

void Task :: setDueDate(const sc::time_point<sc::system_clock>& newTime) {
    dueDate = newTime;
}

void Task :: setCompleted(const bool completion) {
    completed = completion;
}

////////////////////////////////////////////////////////////////////////////////
/* GETTERS */
std::string Task :: getText() const {
    return taskText;
}

urg Task :: getUrgency() const {
    return urgency;
}

sc::time_point<sc::system_clock> Task :: getDueDate() const {
    return dueDate;
}

bool Task :: getCompleted() const {
    return completed;
}