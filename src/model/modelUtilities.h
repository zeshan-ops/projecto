/*

Blank space for documentation later

*/

#ifndef MODEL_UTIL_H
#define MODEL_UTIL_H

#include <string>
#include <chrono>
#include "date.h"

using namespace date;
using namespace std::chrono;

namespace modelUtil {
    time_point<system_clock, seconds> stringToTimePoint(std::string stringTime);
}

#endif