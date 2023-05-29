/*

Temporary testing file, manual testing, prints to command line
checked visually for correctness

*/

#include "viewTable.h"
#include "viewDetail.h"
#include "viewProject.h"
#include "viewTask.h"

int main() {
    std::vector<std::string> task1 = {"0", "Refactor the view to remove possibility of seg faults caused by out-of-range vector indexing", "0", "2023-06-30"};
    std::vector<std::string> task1Header = {"ID", "Text", "Urgency", "Due Date"};

    viewTask taskViewTest(task1Header, task1);

    taskViewTest.render();

    return 0;
}