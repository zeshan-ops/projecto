#include "task.h"

void Task :: editTaskText(std::string newTaskText) {
    taskText = newTaskText;
}

void Task :: editTaskUrgency(int newUrgency) {
    urgency = newUrgency;
}