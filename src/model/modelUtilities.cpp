#include "modelUtilities.h"

///////////////////////////////////////////////////////////////////////////////
time_point<system_clock, seconds> modelUtil :: stringToTimePoint(std::string stringTime) {
    if(stringTime.length() == 10) {
        stringTime += " 00:00:00";
    }
    std::istringstream in(stringTime);
    time_point<system_clock, seconds> tp;
    in >> parse("%F %T", tp);

    return tp;
}