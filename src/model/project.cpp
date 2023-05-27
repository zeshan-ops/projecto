#include "project.h"

////////////////////////////////////////////////////////////////////////////////
/* CONSTRUCTOR */
Project :: Project(std::string name) : projectName(name) {};

////////////////////////////////////////////////////////////////////////////////
/* TASK MANIPULATORS */
void Project :: addTask(const Task& task) {
    tasks.push_back(task);
}

void Project :: editTask(unsigned int taskID, const Task& task) {
    tasks[taskID] = task;
}

void Project :: deleteTask(unsigned int taskID) {
    tasks.erase(tasks.begin()+taskID);
}

void Project :: setTasks(std::vector<Task>& taskList) {
    tasks = taskList;
}

/* LOG MANIPULATORS*/
void Project :: addLog(const Log& log) {
    logs.push_back(log);
}

void Project :: deleteLog(unsigned int logID) {
    logs.erase(logs.begin()+logID);
}

void Project :: setLogs(std::vector<Log>& logList) {
    logs = logList;
}

/* PROJECT SETTERS */
void Project :: setName(std::string newName) {
    projectName = newName;
}

////////////////////////////////////////////////////////////////////////////////
/* TASK GETTERS */
std::vector<Task> Project :: getTasks() const {
    return tasks;
}

Task Project :: getTask(unsigned int taskID) const {
    return tasks[taskID];
}

/* LOG GETTERS */
std::vector<Log> Project :: getLogs() const {
    return logs;
}

Log Project :: getLog(unsigned int logID) const {
    return logs[logID];
}

/* PROJECT GETTERS */
std::string Project :: getName() const {
    return projectName;
}