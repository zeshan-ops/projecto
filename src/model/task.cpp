#include "task.h"

Task :: Task(std::string text) : taskText(text), urgency(0), dueDate(0), completed(false) {};

////////////////////////////////////////////////////////////////////////////////
/* SETTERS */
void Task :: setText(const std::string text) {
    taskText = text;
}

void Task :: setUrgency(const int newUrgency) {
    urgency = newUrgency;
}

void Task :: setDueDate(const int newTime) {
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

int Task :: getUrgency() const {
    return urgency;
}

int Task :: getDueDate() const {
    return dueDate;
}

bool Task :: getCompleted() const {
    return completed;
}