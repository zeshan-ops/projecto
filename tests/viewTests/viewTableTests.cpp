#include "../doctest.h"
#include "../../src/view/viewTable.h"

TEST_SUITE("View Table Tests") {
    TEST_CASE("Generating a full table") {
        std::vector<std::string> tableHeader {"ID", "Text", "P", "Due Date"};
        std::vector<std::vector<std::string>> tableContents;

        std::vector<std::string> task1 {"0", "Lorem ipsum dolores task 1", "", "2023-07-10"};
        std::vector<std::string> task2 {"1", "Expecto patronum, pinder task 2, blah de blah de blah humpty dumpty sat", "L", "2023-08-11"};
        std::vector<std::string> task3 {"2", "Yet another task, refactor something", "H", "2023-07-01"};

        tableContents.push_back(task1); tableContents.push_back(task2); tableContents.push_back(task3);

        std::vector<unsigned int> columnWidths {2, 63, 1, 10};

        viewTable tableGenerator(tableHeader, tableContents);

        std::string generatedString = tableGenerator.render(columnWidths);

        std::stringstream composer;
        composer 
            << "\033[4m\033[1mID\033[0m \033[4m\033[1mText                                                           \033[0m \033[4m\033[1mP\033[0m \033[4m\033[1mDue Date  \033[0m\n" 
            << "0  Lorem ipsum dolores task 1                                        2023-07-10\n"
            << "1  Expecto patronum, pinder task 2, blah de blah de blah humpty... L 2023-08-11\n"
            << "2  Yet another task, refactor something                            H 2023-07-01\n";
        
        std::string expectedString = composer.str();
        
        CHECK(generatedString == expectedString);
    }

    TEST_CASE("Correctly handling errors in table input") {
        std::vector<std::string> tableHeader {};
        std::vector<std::vector<std::string>> tableContents {};
        std::vector<unsigned int> columnWidths {};

        SUBCASE("Three invalid parameters") {
            viewTable tableGenerator(tableHeader, tableContents);
            CHECK(tableGenerator.render(columnWidths) == "ERROR: invalid table parameters.\n");
        }

        SUBCASE("Invalid content and width") {
            tableHeader.push_back("Tester");
            viewTable tableGenerator(tableHeader, tableContents);
            CHECK(tableGenerator.render(columnWidths) == "ERROR: invalid table parameters.\n");
        }

        SUBCASE("Invalid content and header") {
            columnWidths.push_back(1);
            viewTable tableGenerator(tableHeader, tableContents);
            CHECK(tableGenerator.render(columnWidths) == "ERROR: invalid table parameters.\n");
        }

        SUBCASE("Invalid content") {
            columnWidths.push_back(1);
            tableHeader.push_back("Blah");
            viewTable tableGenerator(tableHeader, tableContents);
            CHECK(tableGenerator.render(columnWidths) == "ERROR: invalid table parameters.\n");
        }

        SUBCASE("Invalid header") {
            columnWidths.push_back(1);
            tableContents.push_back({"Blah"});
            viewTable tableGenerator(tableHeader, tableContents);
            CHECK(tableGenerator.render(columnWidths) == "ERROR: invalid table parameters.\n");
        }

        SUBCASE("Invalid columnWidths") {
            tableHeader.push_back("Blah");
            tableContents.push_back({"Blah"});
            viewTable tableGenerator(tableHeader, tableContents);
            CHECK(tableGenerator.render(columnWidths) == "ERROR: invalid table parameters.\n");
        }

        SUBCASE("Mismatched input size") {
            tableHeader.push_back("Blah");
            tableContents.push_back({"Blah"});
            columnWidths.push_back(1); columnWidths.push_back(2);
            viewTable tableGenerator(tableHeader, tableContents);
            CHECK(tableGenerator.render(columnWidths) == "ERROR: number of columns in header doesn't match number of columns in columnWidths.\n");
        }
    }
}