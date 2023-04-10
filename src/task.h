/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#ifndef TASK_H
#define TASK_H

#include <string>
#include <vector>

struct Task {
    std::string taskText;
    int urgency;
    int dueDate;
    std::vector<std::string> tags;
    bool completed;

    void editTaskText(std::string newTaskText);
    void editTaskUrgency(int newUrgency);
    void editTaskDueDate(int newDueDate);
    void deleteTag(int tagIndex);
    void addTag(std::string newTag);
    void editCompletion(bool completion);
};

#endif