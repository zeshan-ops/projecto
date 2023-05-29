#include "viewDetail.h"

///////////////////////////////////////////////////////////////////////////////
viewDetail :: viewDetail(std::vector<std::string> header,
                         std::vector<std::string> content) :
    detailHeaders(header), detailContent(content) {};

///////////////////////////////////////////////////////////////////////////////
std::string viewDetail :: render(bool truncate) {
    if(detailHeaders.size() == 0 || detailContent.size() == 0) {
        return "ERROR: No detail content provided.\n";
    }
    
    if(detailHeaders.size() != detailContent.size()) {
        return "ERROR: Detail headers not the same size as detail content.\n";
    }

    if(truncate) {
        for(unsigned int i = 0; i < detailContent.size(); i++) {
            detailContent[i] = viewUtil::truncateText(detailContent[i], 80-(detailHeaders[i] + ": ").length());
        }
    }

    std::vector<int> headerLengths;
    for(auto& i : detailHeaders) {
        headerLengths.push_back(i.length());
    }

    int maxHeaderLength = *std::max_element(headerLengths.begin(), headerLengths.end());

    std::string detailString;

    for(unsigned int i = 0; i < detailHeaders.size(); i++) {
        std::stringstream composer;
        composer << txtBold << txtDim << std::setw(maxHeaderLength)
                  << detailHeaders[i] << txtReset
                  << ": " 
                  << detailContent[i]
                  << "\n";
        detailString += composer.str();
    }

    return detailString;
}