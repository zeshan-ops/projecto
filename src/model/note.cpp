#include "note.h"

Note :: Note(std::string initialNoteText) {
    noteText = initialNoteText;
}

void Note :: editNoteText(std::string newNoteText) {
    noteText = newNoteText;
}

std::string Note :: getNoteNext() {
    return noteText;
}