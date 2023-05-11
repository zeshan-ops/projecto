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
        sc::time_point<sc::system_clock> logTime;

    public:
        Log(std::string text, sc::time_point<sc::system_clock> time);

        // setters & getters
        void setText(const std::string& newLogText);
        void setTime(const sc::time_point<sc::system_clock>& newTime);

        std::string getText() const;
        sc::time_point<sc::system_clock> getTime() const;

        bool operator==(const Log& a) const {
            return a.logText == logText;
            return a.logTime == logTime;
        }
};

#endif