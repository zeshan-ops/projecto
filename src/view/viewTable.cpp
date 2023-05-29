#include "viewTable.h"

///////////////////////////////////////////////////////////////////////////////
viewTable :: viewTable(std::vector<std::string> header,
                       std::vector<std::vector<std::string>> contents) :
    tableHeader(header), tableContents(contents) {};

///////////////////////////////////////////////////////////////////////////////
std::string viewTable :: render(std::vector<unsigned int> columnWidths) {
    // INVALID INPUT HANDLING
    if(columnWidths.size() == 0 || tableContents.size() == 0 || tableHeader.size() == 0) {
        return "ERROR: invalid table parameters.\n";
    }
    
    if(columnWidths.size() != tableHeader.size()) {
        return "ERROR: number of columns in header doesn't match number of columns in columnWidths.\n";
    }
    
    std::string tableString;

    // Printing the table headers
    for(unsigned int i = 0; i < columnWidths.size(); i++) {
        std::stringstream composer;
        composer << txtUnderline << txtBold << std::left
                 << std::setw((int)columnWidths[i])
                 << tableHeader[i]
                 << txtReset;
        tableString += composer.str();
        if(i != columnWidths.size() - 1) {
            tableString += " ";
        }
    }
    
    // break line
    tableString += '\n';

    // Printing table content
    for(auto& content : tableContents) {
        for(unsigned int i = 0; i < columnWidths.size(); i++) {
            std::stringstream composer;
            composer << std::setw((int)columnWidths[i]) << std::left
                     << viewUtil::truncateText(content[i],columnWidths[i]);
            tableString += composer.str();
            if(i != (columnWidths.size() - 1)) {
                tableString += " ";
            }
        }
        tableString += '\n';
    }

    return tableString;
}