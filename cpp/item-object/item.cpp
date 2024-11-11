#include "../../includes/rapidjson/document.h" 
#include <string>
#include <vector>
#include <unordered_set>
using namespace rapidjson;

enum ItemOperator{
    IN,
    IS,
};


class Item {
    public: 
        Item(std::vector<string> values) {
            this->values = values;
        }
        bool All(Item other){

        }
        bool Any(){

        }
        bool AreUnique(){
             std::unordered_set<std::string> uniqueValues;
    
    for (const auto& value : values) {
        // Try to insert the value into the set
        if (!uniqueValues.insert(value).second) {
            // If insertion fails, a duplicate was found
            return false;
        }
    }
    // If no duplicates were found, return true
    return true;
        }

    private:
        std::vector<string> values;
}

