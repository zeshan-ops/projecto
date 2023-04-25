/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#ifndef NOTE_H
#define NOTE_H

#include <string>

class Note {
    private:
        std::string noteText;

    public:
        Note(std::string initialNoteText);
        void editNoteText(std::string newNoteText);
        std::string getNoteNext();
};

#endif