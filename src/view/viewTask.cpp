#include "viewTask.h"

///////////////////////////////////////////////////////////////////////////////
viewTask :: viewTask(std::vector<std::string> content, std::vector<std::string> header) :
    taskContent(content), taskHeaders(header) {};

///////////////////////////////////////////////////////////////////////////////
void viewTask :: render() {
    viewDetail taskDetail(taskContent, taskHeaders);
    taskDetail.render(false);
}