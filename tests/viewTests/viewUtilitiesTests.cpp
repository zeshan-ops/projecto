#include "../doctest.h"
#include "../../src/view/viewUtilities.h"

TEST_SUITE("View Utilities Test: Truncate Text") {
    TEST_CASE("Trunc length > text length, so do not truncate") {
        CHECK(viewUtil::truncateText("Not truncated", 50) == "Not truncated");
    }

    TEST_CASE("Truncate below threshold") {
        CHECK(viewUtil::truncateText("This is going to be truncated", 15) == "This is...");
    }

    TEST_CASE("Truncate at threshold") {
        CHECK(viewUtil::truncateText("I want this text to truncate here", 19) == "I want this text...");
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

    TEST_CASE("Truncating a date of format YYYY-MM-DD to 10 characters") {
        CHECK(viewUtil::truncateText("2023-02-03", 10) == "2023-02-03");
    }
}

TEST_SUITE("View Utilities Test: Wrap Text") {
    TEST_CASE("Zero wrap length") {
        CHECK(viewUtil::wrapText("Blah blah blah", 0) == "");
    }

    TEST_CASE("Empty string input") {
        CHECK(viewUtil::wrapText("", 10) == "");
    }
    
    TEST_CASE("Wrap length > text length, so do not wrap") {
        CHECK(viewUtil::wrapText("The quick brown fox jumped over the lazy dog", 81) == "The quick brown fox jumped over the lazy dog");
    }

    TEST_CASE("Wrap length = text length, so do not wrap") {
        CHECK(viewUtil::wrapText("The quick brown fox jumped over the lazy dog", 80) == "The quick brown fox jumped over the lazy dog");
    }

    TEST_CASE("Wrap at a non-space character") {
        std::string expectedOuput = "The quick brown\nfox jumped over\nthe lazy dog";
        CHECK(viewUtil::wrapText("The quick brown fox jumped over the lazy dog", 15) == expectedOuput);
    }

    TEST_CASE("Wrap at a space character") {
        CHECK(viewUtil::wrapText("There is a space I want it to wrap at the space, will it do it?",17) ==
               "There is a space\nI want it to wrap\nat the space,\nwill it do it?" );
    }

    TEST_CASE("No spaces wrapping") {
        CHECK(viewUtil::wrapText("123456789123456789123456789123456789", 9) ==
                "123456789\n123456789\n123456789\n123456789\n");
    }
}