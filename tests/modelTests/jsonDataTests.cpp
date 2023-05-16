#include "../doctest.h"

#include "../../src/model/jsonData.h"

TEST_SUITE("JSON Writing Tests") {
    std::ifstream inputFile("testData1.json");

    jsonData storageData1(inputFile);
    
    TEST_CASE("No modification reading and writing") {
        storageData1.writeData("testData2.json");
        std::ifstream inputFile2("testData2.json");

        jsonData storageData2(inputFile2);

        CHECK(storageData1.getData() == storageData2.getData());
    }
}