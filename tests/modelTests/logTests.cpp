#include "../doctest.h"

#include "../../src/model/log.h"

TEST_SUITE("Log Class Tests") {
    TEST_CASE("Constructor initialisation test") {
        Log testLog("Test Log");
        CHECK(testLog.getTimePoint() <= floor<seconds>(system_clock::now()));
        CHECK(floor<minutes>(testLog.getTimePoint()) == floor<minutes>(system_clock::now()));
        CHECK(testLog.getText() == "Test Log");
    }

    TEST_CASE("Returning correct string vector") {
        Log testLog("Test Log");
        testLog.setTime(sys_days{2020_y/5/5} + 6h + 9min + 5s);

        std::vector<std::string> expectedVector = {"2020-05-05 06:09:05", "Test Log"};
        CHECK(testLog.stringVector() == expectedVector);
    }

    TEST_CASE("Equality operator Tests") {
        Log log1("Test Log 1");
        Log log2("Test Log 2");

        log1.setTime(sys_days{2020_y/5/5} + 6h + 9min + 5s);

        SUBCASE("Text and time different") {
            CHECK(log1 != log2);
        }

        SUBCASE("Text different") {
            log2.setTime(log1.getTimePoint());
            CHECK(log1 != log2);
        }

        SUBCASE("Time different") {
            log1.setText(log2.getText());
            CHECK(log1 != log2);
        }

        SUBCASE("Time and text equal") {
            log2.setText(log1.getText());
            log2.setTime(log1.getTimePoint());
            CHECK(log1 == log2);
        }
    }

    TEST_CASE("Less than operator tests") {
        Log log1("Test Log 1");
        Log log2("Test Log 2");

        SUBCASE("LHS less than RHS") {
            log1.setTime(sys_days{2020_y/5/5} + 6h + 9min + 5s);
            CHECK(log1 < log2);
        }

        SUBCASE("LHS more than RHS") {
            log1.setTime(sys_days{2024_y/5/5} + 6h + 9min + 5s);
            CHECK(!(log1 < log2));
        }
    }
 }