/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#ifndef PROJECT_H
#define PROJECT_H

#include <vector>
#include <string>
#include "task.h"
#include "log.h"

class Project {
    private:
        std::string projectName_;
        std::vector<Task> tasks_;
        std::vector<Log> logs_;

    public:
        // Manual constructor
        Project(std::string name);

        // data manipulation methods
        void addTask(const Task& task);
        void editTask(unsigned int taskID, const Task& task);
        void deleteTask(unsigned int taskID);
        void setTasks(std::vector<Task>& taskList);

        void addLog(const Log& log);
        void deleteLog(unsigned int logID);
        void setLogs(std::vector<Log>& logList);

        void setName(std::string newName);

        // getter methods
        std::vector<Task> getTasks() const;
        Task getTask(unsigned int taskID) const;

        std::vector<Log> getLogs() const;
        Log getLog(unsigned int logID) const;

        std::string getName() const;

        // comparison operator
        bool operator==(const Project& a) const {
            return a.tasks_ == tasks_
                && a.logs_ == logs_
                && a.projectName_ == projectName_;
        }
};

#endif