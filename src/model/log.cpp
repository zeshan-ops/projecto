#include "log.h"

///////////////////////////////////////////////////////////////////////////////
Log::Log(std::string text, int time) {
    logText = text;
    logTime = time;
}

///////////////////////////////////////////////////////////////////////////////
/* SETTERS */
void Log::setText(const std::string &newLogText) {
    logText = newLogText;
}

void Log::setTime(const int newTime) {
    logTime = newTime;
}

///////////////////////////////////////////////////////////////////////////////
/* GETTERS */
std::string Log::getText() const {
    return logText;
}

int Log::getTime() const {
    return logTime;
}