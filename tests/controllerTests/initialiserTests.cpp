#include "../doctest.h"
#include "../../src/controller/initialiser.h"

#include <filesystem>
#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>

TEST_SUITE("Controller: initialiser Class Tests") {
    TEST_CASE("Creating data directory and init file when they do not exist") {
        initialiser initialiserTest;

        std::string dataPath = (std::string)std::getenv("HOME") + "/.projecto";

        CHECK(std::filesystem::exists(dataPath));
        CHECK(initialiserTest.dataDirectoryExists());
        CHECK(initialiserTest.initialFileExists());
        CHECK(initialiserTest.getFocusedProjectName() == " ");
        CHECK(!initialiserTest.focusedProjectSet());

        std::filesystem::remove_all(dataPath);

        CHECK(!std::filesystem::exists(dataPath));
    }

    TEST_CASE("Reading init file when it does exist") {
        std::string dataPath = (std::string)std::getenv("HOME") + "/.projecto";

        std::filesystem::create_directory(dataPath);

        std::string initFileText = "FOCUSED_PROJECT\nTest Project 1";
        std::ofstream initDataFile(dataPath + "/initial.txt");

        initDataFile << initFileText;
        initDataFile.close();

        initialiser initer;

        CHECK(initer.getFocusedProjectName() == "Test Project 1");
        CHECK(initer.focusedProjectSet() == true);

        std::filesystem::remove_all(dataPath);
        CHECK(!std::filesystem::exists(dataPath));
    }
}