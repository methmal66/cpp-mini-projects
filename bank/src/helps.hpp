#ifndef HELPS_HPP
#define HELPS_HPP
#include <iostream>
#include <filesystem>

using namespace std;

namespace helps {
    string get_ascii_art();
    filesystem::path find_appdata_path();
}

#endif