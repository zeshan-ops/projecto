#include "task.h"

Task :: Task(std::string newTaskText, int newUrgency, int newDueDate) {
    taskText = newTaskText;
    urgency = newUrgency;
    dueDate = newDueDate;
    completed = false;
}

void Task :: editTaskText(std::string newTaskText) {
    taskText = newTaskText;
}

void Task :: editTaskUrgency(int newUrgency) {
    urgency = newUrgency;
}

void Task :: editTaskDueDate(int newDueDate) {
    dueDate = newDueDate;
}

void Task :: editCompletion(bool completion) {
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