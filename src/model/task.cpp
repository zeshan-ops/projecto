#include "task.h"

Task :: Task(std::string newTaskText, int newUrgency, int newDueDate) {
    taskText = newTaskText;
    urgency = newUrgency;
    dueDate = newDueDate;
    completed = false;
}

void Task :: editTaskText(const std::string& newTaskText) {
    taskText = newTaskText;
}

void Task :: editTaskUrgency(const int& newUrgency) {
    urgency = newUrgency;
}

void Task :: editTaskDueDate(const int& newDueDate) {
    dueDate = newDueDate;
}

void Task :: editCompletion(const bool& completion) {
    completed = completion;
}

std::string Task :: getTaskText() {
    return taskText;
}

int Task :: getUrgency() {
    return urgency;
}

int Task :: getDueDate() {
    return dueDate;
}

bool Task :: isCompleted() {
    if (completed) { return true; }
    else { return false; }
}