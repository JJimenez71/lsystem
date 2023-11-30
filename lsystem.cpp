#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include "raylib.h"

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
    //std::cout << "Starting Axiom: " + gen << std::endl;
    for(int i = 0; i < n; i++){

        std::cout << "Gen " + std::to_string(i) + ": " + gen << std::endl;
        int pos = 0;
        do{
            char var = gen[pos];
            //std::cout << gen[pos] << std::endl;
            if(ls.rules.find(var) != ls.rules.end()) {
                // Insert our production rule
                std::string val = ls.rules[var];
                gen.replace(pos, 1, val);
                pos += val.size();
            }else{
                pos += 1;
            }
        }while(pos < gen.size());
    }
    std::cout << "Final Axiom: " + gen << std::endl;

}


int main(){
    // Initialize our variables
    std::vector<char> v;
    v.push_back('F');
    //v.push_back('1');

    // Initialize our constants
    std::vector<char> c;
    c.push_back('[');
    c.push_back(']');

    // Initialize our axiom
    std::string s = "F";

    // Initialize our production rules
    std::unordered_map<char, std::string> m;
    m['F'] = "F+F−F−F+F";
    //m['0'] = "1[0]0";

    LSystem ls = {v, c, s, m};
    create_generation(ls, 5);
    return 0;
}
