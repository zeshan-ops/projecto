/*

Blank space for documentation later

*/

#ifndef DATAPARSER_H
#define DATAPARSER_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "task.h"
#include "note.h"

class dataReader {
    private:
        std::vector<Task> tasks;
        std::vector<Note> notes;
        std::string lastAction;
        std::string description;
    
    public:
        bool fileValidater(std::string filename);
        void objectPopulator(std::string filename);

        // getter functions
};




#endif