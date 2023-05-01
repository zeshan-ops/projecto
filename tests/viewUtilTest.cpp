#include "doctest.h"
#include "../src/view/viewUtilities.h"

TEST_SUITE("View Utility Function Tests") {
    TEST_CASE("String Truncation Tests") {
        int truncLength = 20;

        SUBCASE("Space as final character") {
            std::string inputText = "0123456789012345 789TRUNCATED";
            std::string expectedResult = "0123456789012345...";
            CHECK(truncateText(inputText, truncLength) == expectedResult);
        }

        SUBCASE("Non space as final character") {
            std::string inputText = "012345678901 3456789TRUNCATED";
            std::string expectedResult = "012345678901...";
            CHECK(truncateText(inputText, truncLength) == expectedResult);
        }

        SUBCASE("Multiple spaces") {
            std::string inputText = "0123 56789 12345 789TRUNCATED";
            std::string expectedResult = "0123 56789 12345...";
            CHECK(truncateText(inputText, truncLength) == expectedResult);
        }

        SUBCASE("Non-truncating string") {
            std::string inputText = "0123 56789 12345 789";
            std::string expectedResult = "0123 56789 12345 789";
            CHECK(truncateText(inputText, truncLength) == expectedResult);
        }

        SUBCASE("Error handling") {
            std::string inputText = "0123456789012345678901234567890";
            std::string expectedResult = "Error truncating text";
            CHECK(truncateText(inputText, truncLength) == expectedResult);
        }
    }
}