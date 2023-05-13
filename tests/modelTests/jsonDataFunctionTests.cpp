#include "../doctest.h"

#include "../../src/model/jsonReader.h"
#include "../../src/model/jsonWriter.h"

TEST_SUITE("JSON Writing Tests") {
    jsonReader storageData1("testData1.json");

    jsonWriter outputData(storageData1.getAllData());
    
    TEST_CASE("No modification reading and writing") {
        outputData.writeData("testData2.json");
        jsonReader storageData2("testData2.json");

        CHECK(storageData1.getAllData() == storageData2.getAllData());
    }
}