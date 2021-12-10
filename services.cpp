#include <iostream>
#include <filesystem>
#include <fstream>
#include <random>

using namespace std;
namespace fs = filesystem;

bool account_already_exist(string acc_no) {
    for (const auto& file : fs::directory_iterator(".accounts"))
        if (acc_no == file.path().filename())
            return true;

    return false;
}

string generate_random_account_no() {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> distribute(10000000, 99999999);
    return to_string(distribute(generator));
}

namespace services {

    string create_new_account(string name) {
        string account_no;
        do
            account_no = generate_random_account_no();
        while (account_already_exist(account_no));

        ofstream file(fs::path(".accounts").append(account_no));
        file << "name=" << name;
        return "Account " + account_no + " created for " + name;
    }

    bool close_account(string account_no) {
        if (account_already_exist(account_no)) {
            fs::remove(fs::path(".accounts").append(account_no));
            return true;
        }
        return false;
    }
}