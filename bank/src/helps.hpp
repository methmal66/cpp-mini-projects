#ifndef HELPS_HPP
#define HELPS_HPP
#include <iostream>
#include <filesystem>

using namespace std;

namespace helps {
    string get_ascii_art();
    filesystem::path find_appdata_path();
    bool account_exist(string);
    void validate_account(string);
    string generate_random_account_no();
}

#endif