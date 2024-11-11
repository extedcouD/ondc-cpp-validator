#include "../../includes/rapidjson/document.h" 
#include <string>
#include <iostream>

using namespace rapidjson;

class Item {
    public: 
            char* helloFromItem(){
            return "guys";
        }

        void testRapid() {
    const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
    Document d;
    d.Parse(json);

    // Check if parsing was successful and if the expected keys exist
    if (d.HasParseError()) {
        std::cout << "Failed to parse JSON." << std::endl;
        return;
    }

    if (d.HasMember("project") && d["project"].IsString()) {
        std::cout << "Project: " << d["project"].GetString() << std::endl;
    } else {
        std::cout << "Project key not found or is not a string." << std::endl;
    }

    if (d.HasMember("stars") && d["stars"].IsInt()) {
        std::cout << "Stars: " << d["stars"].GetInt() << std::endl;
    } else {
        std::cout << "Stars key not found or is not an integer." << std::endl;
    }
}
};

