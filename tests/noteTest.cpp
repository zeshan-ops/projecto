#include "doctest.h"
#include "../src/model/note.h"

TEST_SUITE("Note Object Tests") {
    TEST_CASE("Note Initialisation Test") {
        Note testNote("Note initialisation");
        CHECK(testNote.getNoteNext().compare("Note initialisation") == 0);
    }

    TEST_CASE("Note Modification Test") {
        Note testNote("Note text");
        testNote.editNoteText("Edited text");
        CHECK(testNote.getNoteNext().compare("Edited text") == 0);
    }
}