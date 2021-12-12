#include <iostream>
#include <fstream>

using namespace std;

namespace helps {
    string get_ascii_art() {
        string art;
        getline(std::ifstream("ascii_art.txt"), art, '\0');
        return art;
    }
}