#include "../doctest.h"
#include "../../src/view/viewProject.h"

TEST_SUITE("View Project Tests") {
    TEST_CASE("Generating a full project") {
        std::vector<std::vector<std::string>> tList = {
            {"0", "Blurg farg jork lorem", "H", "2023-02-02"},
            {"1", "Blurg farg jork lorem", "M", "2023-02-02"},
            {"2", "Blurg farg jork lorem ipsum dolores, truncation galore my good sir, over yonder doth thee find that which ye seek", "L", "2023-02-02"},
            {"3", "Blurg farg jork lorem", "H", "2023-02-02"}
        };

        std::vector<std::string> tHeaders = {
            "ID", "Text", "P", "Due Date"
        };

        std::vector<std::string> last = {
            "2022-02-14 14:28:30", "Lorem ipsum dolores, equitat vai sorquet epilin aquila et vac, loresium dolorium the quick brown fox jumper over the lazy dog. Monkeys bashing keyboards would eventually write the entire works of Shakespeare. Seek the truth, return to the path. Etc bon soir mon cherie."
        };

        std::string name {"Test Project 1"};
        
        viewProject testViewProject(tList, tHeaders, last, name);

        std::stringstream composer;
        
        composer << "\n";
        composer << txtBold << txtGreen << "                                 Test Project 1";
        composer << "\n\n";
        composer << "TASKS" << txtReset << "\n";
        composer 
            << "\033[4m\033[1mID\033[0m \033[4m\033[1mText                                                           \033[0m \033[4m\033[1mP\033[0m \033[4m\033[1mDue Date  \033[0m\n" 
            << "0  Blurg farg jork lorem                                           H 2023-02-02\n"
            << "1  Blurg farg jork lorem                                           M 2023-02-02\n"
            << "2  Blurg farg jork lorem ipsum dolores, truncation galore my...    L 2023-02-02\n"
            << "3  Blurg farg jork lorem                                           H 2023-02-02\n";
        composer << txtDim << "(4 tasks)" << txtReset << "\n";
        composer << "\n";

        composer << txtGreen << txtBold << "LAST ACTION" << txtReset;
        composer << "\n";
        composer << txtBold << txtDim << last[0] << txtReset;
        composer << "\n";
        composer << "Lorem ipsum dolores, equitat vai sorquet epilin aquila et vac, loresium dolorium\nthe quick brown fox jumper over the lazy dog. Monkeys bashing keyboards would\neventually write the entire works of Shakespeare. Seek the truth, return to the\npath. Etc bon soir mon cherie.";    
        composer << "\n";

        std::string expectedString = composer.str();

        CHECK(testViewProject.render() == expectedString);
    }

    TEST_CASE("Generating a project with no tasks or logs") {
        std::vector<std::vector<std::string>> tList;
        std::vector<std::string> last;
        std::string name {"Test Project 1"};
        std::vector<std::string> tHeaders = {
            "ID", "Text", "P", "Due Date"
        };

        viewProject testViewProject(tList, tHeaders, last, name);

        std::stringstream composer;
        
        composer << "\n";
        composer << txtBold << txtGreen << "                                 Test Project 1";
        composer << "\n\n";
        composer << "TASKS" << txtReset << "\n";
        composer << txtDim << "No outstanding tasks!" << txtReset << "\n";
        composer << "\n";

        composer << txtGreen << txtBold << "LAST ACTION" << txtReset;
        composer << "\n";
        composer << txtDim << "No last action!" << txtReset;
        composer << "\n";

        std::string expectedString = composer.str();

        CHECK(testViewProject.render() == expectedString);
    }
}