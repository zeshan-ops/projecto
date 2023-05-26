#include "project.h"

////////////////////////////////////////////////////////////////////////////////
/* CONSTRUCTOR */
Project :: Project(std::string name) : projectName(name) {};

////////////////////////////////////////////////////////////////////////////////
/* TASK MANIPULATORS */
void Project :: addTask(const Task& task) {
    tasks.push_back(task);
}

void Project :: editTask(int taskID, const Task& task) {
    tasks[taskID] = task;
}

void Project :: deleteTask(int taskID) {
    tasks.erase(tasks.begin()+taskID);
}

void Project :: setTasks(std::vector<Task>& taskList) {
    tasks = taskList;
}

/* LOG MANIPULATORS*/
void Project :: addLog(const Log& log) {
    logs.push_back(log);
}

void Project :: deleteLog(int logID) {
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

Task Project :: getTask(int taskID) const {
    return tasks[taskID];
}

/* LOG GETTERS */
std::vector<Log> Project :: getLogs() const {
    return logs;
}

Log Project :: getLog(int logID) const {
    return logs[logID];
}

/* PROJECT GETTERS */
std::string Project :: getName() const {
    return projectName;
}