#include "projectView.h"
#include "../model/txtDataUtility.h"

int main() {
    json projectData = fileReader("view_tester.json");

    Project project(projectData);

    showProjectView(project);

    writeProjectData(project.outputProjectData(), "projectoData.json");

    json projectData2 = fileReader("projectoData.json");

    Project project2(projectData2);
    showProjectView(project2);

    return 0;
}