#include "../doctest.h"
#include "../../src/controller/initialiser.h"

#include <filesystem>

TEST_SUITE("Controller: initialiser Class Tests") {
    TEST_CASE("Creating data directory when it does not exist") {
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
}