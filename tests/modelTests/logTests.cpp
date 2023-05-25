#include "../doctest.h"

#include "../../src/model/log.h"

TEST_SUITE("Log Class Tests") {
    TEST_CASE("Constructor initialisation test") {
        Log testLog("Test Log", 0);
        CHECK(testLog.getText() == "Test Log");
        CHECK(testLog.getTime() == 0);
    }

    TEST_CASE("Comparison operator tests") {
        Log logA("Log A", 0);
        Log logB("Log B", 0);
        
        SUBCASE("Checking unequal logs") {
            CHECK(logA != logB);
        }

        SUBCASE("Checking equal tasks") {
            logB.setText("Log A");
            CHECK(logA == logB);
        }
    }
}