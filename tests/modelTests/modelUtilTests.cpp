#include "../doctest.h"
#include "../../src/model/modelUtilities.h"
#include <iostream>

TEST_SUITE("Model Utility Tests") {
    TEST_CASE("Converting strings to time_points") {
        SUBCASE("String in format XXXX-XX-XX") {
            time_point<system_clock, seconds> funcTP = modelUtil :: stringToTimePoint("2020-01-01");
            CHECK(sys_days{2020_y/1/1} + 0h + 0min + 0s == funcTP);
            CHECK(sys_days{2020_y/1/1} == floor<days>(funcTP));
        }
        
        SUBCASE("String in format XXXX-XX-XX HH:MM:SS") {
            time_point<system_clock, seconds> funcTP = modelUtil :: stringToTimePoint("2020-02-03 01:02:03");
            CHECK(sys_days{2020_y/2/3} + 1h + 2min + 3s == funcTP);
        }
    }
}