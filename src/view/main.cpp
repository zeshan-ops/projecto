#include "projectView.h"
#include "../model/txtDataUtility.h"

int main() {
    json projectData = fileReader("view_tester.json");

    Project project(projectData);

    showProjectView(project);

    return 0;

}