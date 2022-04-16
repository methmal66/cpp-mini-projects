#include <iostream>
#include <fstream>
#include <random>
#include <filesystem>
#include <stdexcept>
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

    bool account_exist(string account_no) {
        for (const auto& file : filesystem::directory_iterator(".accounts"))
            if (account_no == file.path().filename())
                return true;
        return false;
    }

    void validate_account(string account_no) {
        for (const auto& file : filesystem::directory_iterator(".accounts"))
            if (account_no == file.path().filename())
                return;
        throw invalid_argument(": Account does not exist :(");
    }

    string generate_random_account_no() {
        random_device rd;
        mt19937 generator(rd());
        uniform_int_distribution<> distribute(10000000, 99999999);
        return to_string(distribute(generator));
    }
}