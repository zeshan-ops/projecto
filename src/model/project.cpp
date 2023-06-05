#include "project.h"

////////////////////////////////////////////////////////////////////////////////
/* CONSTRUCTOR */
Project :: Project(std::string name) : projectName_(name) {};

////////////////////////////////////////////////////////////////////////////////
/* TASK MANIPULATORS */
void Project :: addTask(const Task& task) {
    tasks_.push_back(task);
    if (tasks_.size() > 1) {
        std::sort(tasks_.begin(), tasks_.end(), std::greater<Task>());
    }
}

void Project :: editTask(unsigned int taskID, const Task& task) {
    tasks_[taskID] = task;
    if (tasks_.size() > 1) {
        std::sort(tasks_.begin(), tasks_.end(), std::greater<Task>());
    }
}

void Project :: deleteTask(unsigned int taskID) {
    tasks_.erase(tasks_.begin()+taskID);
}

void Project :: setTasks(std::vector<Task>& taskList) {
    tasks_ = taskList;
    if (tasks_.size() > 1) {
        std::sort(tasks_.begin(), tasks_.end(), std::greater<Task>());
    }

}

/* LOG MANIPULATORS*/
void Project :: addLog(const Log& log) {
    logs_.push_back(log);
    if (logs_.size() > 1) {
        std::sort(logs_.begin(), logs_.end());
    }
}

void Project :: deleteLog(unsigned int logID) {
    logs_.erase(logs_.begin()+logID);
}

void Project :: setLogs(std::vector<Log>& logList) {
    logs_ = logList;
    if (logs_.size() > 1) {
        std::sort(logs_.begin(), logs_.end());
    }
}

/* PROJECT SETTERS */
void Project :: setName(std::string newName) {
    projectName_ = newName;
}

////////////////////////////////////////////////////////////////////////////////
/* TASK GETTERS */
std::vector<Task> Project :: getTasks() const {
    return tasks_;
}

Task Project :: getTask(unsigned int taskID) const {
    return tasks_[taskID];
}

/* LOG GETTERS */
std::vector<Log> Project :: getLogs() const {
    return logs_;
}

Log Project :: getLog(unsigned int logID) const {
    return logs_[logID];
}

/* PROJECT GETTERS */
std::string Project :: getName() const {
    return projectName_;
}