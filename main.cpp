#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

struct LSystem{
    std::vector<char> vars; // Alphabet of LSystem
    std::vector<char> constants; // Other characters of LSystem
    std::string axiom; // Starting point of L System
    std::unordered_map<char, std::string> rules; // Production Rules of LSystem
};

/*
*   This function serves to create n generations of a LindenMayer System and return that string
*/
void create_generation(LSystem &ls, int n){
    std::string gen = ls.axiom; // We will use this to append for future generations
    std::cout << "Starting Axiom: " + gen << std::endl;
    for(int i = 0; i < n; i++){

        for(int pos = 0; pos < gen.size(); pos++){
            char var = ls.axiom[var];
            if(ls.rules.find(var) != ls.rules.end()) {
                // Insert our production rule
                // TODO: FINISH INSERTION LOGIC 
                std::string val = ls.rules[var];
                gen.replace(pos + 1, val);
                pos += val.size() - 1;
            }
        }
        std::cout << "Gen " + i + ": " + gen << std::endl;
    }
    std::cout << "Final Axiom: " + gen << std::endl;

}


int main(){
    // Initialize our variables
    std::vector<char> v;
    v.push_back('A');
    v.push_back('B');

    // Initialize our constants
    std::vector<char> c;

    // Initialize our axiom
    std::string s = "A";

    // Initialize our production rules
    std::unordered_map<char, std::string> m;
    m['A'] = "B";

    LSystem ls = {v, c, s, m};
    create_generation(ls, 3);
    return 0;
}
