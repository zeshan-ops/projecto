#include "../doctest.h"
#include "../../src/view/viewUtilities.h"

TEST_SUITE("View Utilities Test: Truncate Text") {
    TEST_CASE("Returning text without truncation") {
        CHECK(viewUtil::truncateText("Not truncated", 50) == "Not truncated");
    }

    TEST_CASE("Returning text with truncation") {
        CHECK(viewUtil::truncateText("This is going to be truncated", 15) == "This is going...");
    }

    TEST_CASE("Not truncating if trunc length is zero") {
        CHECK(viewUtil::truncateText("Do not truncate this", 0) == "Do not truncate this"); 
    }

    TEST_CASE("Dealing with empty string") {
        CHECK(viewUtil::truncateText("", 10) == "");
    }

    TEST_CASE("Dealing with a string without spaces") {
        CHECK(viewUtil::truncateText("LOREMIPSUMDOLORES", 10) == "LOREMIP...");
    }
}