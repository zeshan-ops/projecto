#include "../doctest.h"
#include "../../src/view/viewDetail.h"


TEST_SUITE("View Detail Tests") {
    TEST_CASE("Non truncated output") {
        std::vector<std::string> detailHeader {"ID", "Time", "Text"};
        std::vector<std::string> detailContent {
            "8", "2023-05-06 13:47:58", "Testing if it'll print non truncated text, lorem ipsum, blah blah blah"
        };

        viewDetail detailTest(detailHeader, detailContent);

        std::string generatedDetail {detailTest.render(false)};

        std::string expectedDetail {
            "\033[1m\033[2m  ID\033[0m: 8\n\033[1m\033[2mTime\033[0m: 2023-05-06 13:47:58\n\033[1m\033[2mText\033[0m: Testing if it'll print non truncated text, lorem ipsum, blah blah blah\n"
        };

        CHECK(generatedDetail == expectedDetail);
    }

    TEST_CASE("Truncated output") {
        std::vector<std::string> detailHeader {"ID", "Time", "Text"};
        std::vector<std::string> detailContent {
            "8", "2023-05-06 13:47:58", "Testing if it'll print non truncated text, lorem ipsum, blah blah blah blah blah blah"
        };

        viewDetail detailTest(detailHeader, detailContent);

        std::string generatedDetail {detailTest.render(true)};

        std::string expectedDetail {
            "\033[1m\033[2m  ID\033[0m: 8\n\033[1m\033[2mTime\033[0m: 2023-05-06 13:47:58\n\033[1m\033[2mText\033[0m: Testing if it'll print non truncated text, lorem ipsum, blah blah blah...\n"
        };

        CHECK(generatedDetail == expectedDetail);
    }

    TEST_CASE("Dealing with invalid input") {
        std::vector<std::string> header;
        std::vector<std::string> detail;

        SUBCASE("Both vectors empty") {
            viewDetail generatedDetail(header,detail);
            CHECK(generatedDetail.render(true) == "ERROR: No detail content provided.\n");
            CHECK(generatedDetail.render(false) == "ERROR: No detail content provided.\n");
        }

        SUBCASE("Header vector empty") {
            header.push_back("Text");
            viewDetail generatedDetail(header,detail);
            CHECK(generatedDetail.render(true) == "ERROR: No detail content provided.\n");
            CHECK(generatedDetail.render(false) == "ERROR: No detail content provided.\n");
        }

        SUBCASE("Detail vector empty") {
            detail.push_back("lorem ipsum blah");
            viewDetail generatedDetail(header,detail);
            CHECK(generatedDetail.render(true) == "ERROR: No detail content provided.\n");
            CHECK(generatedDetail.render(false) == "ERROR: No detail content provided.\n");
        }

        SUBCASE("Mismatched vector sizes") {
            detail.push_back("as"); detail.push_back("asda");
            header.push_back("column 1");
            viewDetail generatedDetail(header,detail);
            CHECK(generatedDetail.render(true) == "ERROR: Mismatched header and content size.\n");
            CHECK(generatedDetail.render(false) == "ERROR: Mismatched header and content size.\n");
        }
    }
}