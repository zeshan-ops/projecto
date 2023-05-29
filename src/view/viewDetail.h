/*

BLANK SPACE FOR DOCUMENTATION LATER

*/

#ifndef VIEWDETAIL_H
#define VIEWDETAIL_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include "ansiMacros.h"
#include "viewUtilities.h"

class viewDetail {
    private:
        std::vector<std::string> detailHeaders;
        std::vector<std::string> detailContent;
    public:
        viewDetail(std::vector<std::string> headers,
                   std::vector<std::string> content);

        std::string render(bool truncate);
};

#endif