#include "projectView.h"
#include "../model/jsonDataUtility.h"

int main() {
    json projectData = fileReader("projectoData.json");

    Project project(projectData);

    showProjectView(project);

    return 0;
}