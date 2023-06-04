/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#ifndef LOG_H
#define LOG_H

#include <string>
#include <chrono>
#include "date.h"

using namespace date;
using namespace std::chrono;

class Log {
    private:
        std::string logText_;
        time_point<system_clock, seconds> logTime_;

    public:
        Log(std::string text);

        // setters & getters
        void setText(const std::string logText);
        void setTime(const time_point<system_clock, seconds>& logTime);

        std::string getText() const;
        time_point<system_clock, seconds> getTimePoint() const;

        bool operator==(const Log& a) const {
            return a.logText_ == logText_
                && a.logTime_ == logTime_;
        }
};

#endif