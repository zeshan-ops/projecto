#include "log.h"

///////////////////////////////////////////////////////////////////////////////
Log::Log(std::string text) : logText_(text), logTime_(floor<seconds>(system_clock::now())) {};

///////////////////////////////////////////////////////////////////////////////
/* SETTERS */
void Log::setText(const std::string logText) {
    logText_ = logText;
}

void Log::setTime(const time_point<system_clock, seconds>& logTime) {
    logTime_ = logTime;
}

///////////////////////////////////////////////////////////////////////////////
/* GETTERS */
std::string Log::getText() const {
    return logText_;
}

time_point<system_clock, seconds> Log::getTimePoint() const {
    return logTime_;
}