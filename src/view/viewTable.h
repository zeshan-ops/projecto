/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#ifndef VIEWTABLE_H
#define VIEWTABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include "ansiMacros.h"
#include "viewUtilities.h"

class viewTable {
    private:
        std::vector<std::string> tableHeader;
        std::vector<std::vector<std::string>> tableContents;
    public:
        viewTable(std::vector<std::string> tableHeader,
                  std::vector<std::vector<std::string>> tableContents);
        
        std::string render(std::vector<unsigned int> columnWidths);
};

#endif