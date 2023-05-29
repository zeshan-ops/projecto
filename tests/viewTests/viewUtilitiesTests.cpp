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

TEST_SUITE("View Utilities Test: Wrap Text") {
    TEST_CASE("Wrap length > text length") {
        CHECK(viewUtil::wrapText("The quick brown fox jumped over the lazy dog", 81) == "The quick brown fox jumped over the lazy dog");
    }

    TEST_CASE("Wrap length = text length") {
        CHECK(viewUtil::wrapText("The quick brown fox jumped over the lazy dog", 80) == "The quick brown fox jumped over the lazy dog");
    }

    TEST_CASE("Wrap length < text length") {
        std::string expectedOuput = "The quick brown\nfox jumped over\nthe lazy dog";
        CHECK(viewUtil::wrapText("The quick brown fox jumped over the lazy dog", 15) == expectedOuput);
    }

    TEST_CASE("Zero wrap length") {
        CHECK(viewUtil::wrapText("Blah blah blah", 0) == "");
    }

    TEST_CASE("Empty string input") {
        CHECK(viewUtil::wrapText("", 10) == "");
    }
}