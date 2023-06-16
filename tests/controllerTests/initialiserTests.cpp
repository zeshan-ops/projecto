#include "../doctest.h"
#include "../../src/controller/initialiser.h"

#include <filesystem>
#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>

TEST_SUITE("Controller: initialiser Class Tests") {
    TEST_CASE("Initialisation when data directory and init file do not exist") {
        initialiser initialiserTest;

        std::string dataPath = (std::string)std::getenv("HOME") + "/.projecto";

        CHECK(std::filesystem::exists(dataPath));
        CHECK(initialiserTest.dataDirectoryExists());
        CHECK(initialiserTest.initialFileExists());
        CHECK(initialiserTest.getFocusedProjectName() == "FOCUSED PROJECT NOT SET");
        CHECK(!initialiserTest.focusedProjectSet());

        std::filesystem::remove_all(dataPath);

        CHECK(!std::filesystem::exists(dataPath));
    }

    TEST_CASE("Initialisation when data directory exists but init file does not") {
        std::string dataPath = (std::string)std::getenv("HOME") + "/.projecto";

        std::filesystem::create_directory(dataPath);

        initialiser initer;

        CHECK(std::filesystem::exists(dataPath));
        CHECK(std::filesystem::exists(dataPath + "/initial.txt"));

        CHECK(initer.getFocusedProjectName() == "FOCUSED PROJECT NOT SET");
        CHECK(!initer.focusedProjectSet());

        std::string expectedInitText = "FOCUSED_PROJECTFOCUSED PROJECT NOT SET";

        std::string line;
        std::string generatedInitFileText;
        std::ifstream generatedInitFile(dataPath + "/initial.txt");

        while (std::getline(generatedInitFile, line)) {
            generatedInitFileText += line;
        }

        CHECK(generatedInitFileText == expectedInitText);

        std::filesystem::remove_all(dataPath);
        CHECK(!std::filesystem::exists(dataPath));
    }

    TEST_CASE("Initialisation when init file exists and has correct format") {
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

    TEST_CASE("Initialisation when init file exists but has no header") {
        std::string dataPath = (std::string)std::getenv("HOME") + "/.projecto";

        std::filesystem::create_directory(dataPath);

        std::string initFileText = "Blah blah\nBlah blah\nHerp derp\nBorh flork";
        std::ofstream initDataFile(dataPath + "/initial.txt");

        initDataFile << initFileText;
        initDataFile.close();

        initialiser initer;

        CHECK(std::filesystem::exists(dataPath + "/initial.txt"));
        CHECK(initer.getFocusedProjectName() == "FOCUSED PROJECT NOT SET");
        CHECK(!initer.focusedProjectSet());

        std::string expectedInitText = "FOCUSED_PROJECTFOCUSED PROJECT NOT SET";

        std::string line;
        std::string generatedInitFileText;
        std::ifstream generatedInitFile(dataPath + "/initial.txt");

        while (std::getline(generatedInitFile, line)) {
            generatedInitFileText += line;
        }

        CHECK(generatedInitFileText == expectedInitText);

        std::filesystem::remove_all(dataPath);
        CHECK(!std::filesystem::exists(dataPath));
    }

    TEST_CASE("Initialisation when init file exists but no text after header") {
        std::string dataPath = (std::string)std::getenv("HOME") + "/.projecto";

        std::filesystem::create_directory(dataPath);

        std::string initFileText = "FOCUSED_PROJECT\n";
        std::ofstream initDataFile(dataPath + "/initial.txt");

        initDataFile << initFileText;
        initDataFile.close();

        initialiser initer;

        CHECK(std::filesystem::exists(dataPath + "/initial.txt"));
        CHECK(initer.getFocusedProjectName() == "FOCUSED PROJECT NOT SET");
        CHECK(!initer.focusedProjectSet());

        std::string expectedInitText = "FOCUSED_PROJECTFOCUSED PROJECT NOT SET";

        std::string line;
        std::string generatedInitFileText;
        std::ifstream generatedInitFile(dataPath + "/initial.txt");

        while (std::getline(generatedInitFile, line)) {
            generatedInitFileText += line;
        }

        CHECK(generatedInitFileText == expectedInitText);

        std::filesystem::remove_all(dataPath);
        CHECK(!std::filesystem::exists(dataPath));   
    }
}