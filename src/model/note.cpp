#include "note.h"

Note :: Note(std::string initialNoteText) {
    noteText = initialNoteText;
}

void Note :: editNoteText(const std::string& newNoteText) {
    noteText = newNoteText;
}

std::string Note :: getNoteNext() {
    return noteText;
}