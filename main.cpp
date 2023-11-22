#include <iostream>
#include <map>
#include <string>

struct Tree{
    std::string vars;
    std::string constants;
    std::string axiom;
    std::map<std::string, std::string> rules;
};


int main(){
    std::map<std::string, std::string> m;
    m["A"] = "B";
    Tree tree = {"A B", "", "A", m};

    return 0;
}
