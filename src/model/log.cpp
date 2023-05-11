#include "log.h"

///////////////////////////////////////////////////////////////////////////////
Log::Log(std::string text, sc::time_point<sc::system_clock> time) {
    logText = text;
    logTime = time;
}

///////////////////////////////////////////////////////////////////////////////
/* SETTERS */
void Log::setText(const std::string &newLogText) {
    logText = newLogText;
}

void Log::setTime(const sc::time_point<sc::system_clock>& newTime) {
    logTime = newTime;
}

///////////////////////////////////////////////////////////////////////////////
/* GETTERS */
std::string Log::getText() const {
    return logText;
}

sc::time_point<sc::system_clock> Log::getTime() const {
    return logTime;
}