/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#ifndef LOG_H
#define LOG_H

#include <string>
#include <chrono>

namespace sc = std::chrono;

class Log {
    private:
        std::string logText;
        int logTime;

    public:
        Log(std::string text, int time);

        // setters & getters
        void setText(const std::string& newLogText);
        void setTime(const int newTime);

        std::string getText() const;
        int getTime() const;

        bool operator==(const Log& a) const {
            return a.logText == logText;
            return a.logTime == logTime;
        }
};

#endif