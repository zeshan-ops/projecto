#include "../doctest.h"
#include "../../src/view/viewProject.h"

TEST_SUITE("View Project Tests") {
    TEST_CASE("Generating a full project") {
        std::vector<std::vector<std::string>> tList = {
            {"0", "Blurg farg jork lorem", "H", "2023-02-02"},
            {"2", "Blurg farg jork lorem", "M", "2023-02-02"},
            {"3", "Blurg farg jork lorem ipsum dolores, truncation galore my good sir, over yonder doth thee find that which ye seek", "L", "2023-02-02"},
            {"4", "Blurg farg jork lorem", "H", "2023-02-02"}
        };

        std::vector<std::string> tHeaders = {
            "ID", "Text", "P", "Due Date"
        };

        std::vector<std::string> last = {
            "2022-02-14 14:28:30", "Lorem ipsum dolores, equitat vai sorquet epilin aquila et vac, loresium dolorium the quick brown fox jumper over the lazy dog. Monkeys bashing keyboards would eventually write the entire works of Shakespeare. Seek the truth, return to the path. Etc bon soir mon cherie."
        };

        std::string name {"Test Project 1"};
        
        viewProject testViewProject(tList, tHeaders, last, name);

        std::cout << testViewProject.render();
    }
}