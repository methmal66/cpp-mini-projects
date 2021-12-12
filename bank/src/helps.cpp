#include <iostream>
#include <fstream>
#include <filesystem>
#include <unistd.h>

using namespace std;

namespace helps {
    string get_ascii_art() {
        string art;
        getline(std::ifstream("ascii_art.txt"), art, '\0');
        return art;
    }

    filesystem::path find_appdata_path() {
        return filesystem::canonical(".accounts");
    }

}