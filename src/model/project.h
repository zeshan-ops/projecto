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
        std::string projectName;
        std::vector<Task> tasks;
        std::vector<Log> logs;

    public:
        // Manual constructor
        Project(std::string name);

        // data manipulation methods
        void addTask(const Task& task);
        void editTask(int taskID, const Task& task);
        void deleteTask(int taskID);
        void setTasks(std::vector<Task>& taskList);

        void addLog(const Log& log);
        void deleteLog(int logID);
        void setLogs(std::vector<Log>& logList);

        void setName(std::string newName);

        // getter methods
        std::vector<Task> getTasks() const;
        Task getTask(int taskID) const;

        std::vector<Log> getLogs() const;
        Log getLog(int logID) const;

        std::string getName() const;

        // comparison operator
        bool operator==(const Project& a) const {
            return a.tasks == tasks
                && a.logs == logs
                && a.projectName == projectName;
        }
};

#endif