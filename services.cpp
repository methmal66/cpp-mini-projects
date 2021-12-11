#include <iostream>
#include <filesystem>
#include <fstream>
#include <random>
#include <string>

using namespace std;
namespace fs = filesystem;

bool account_exist(string acc_no) {
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
        while (account_exist(account_no));

        ofstream file(fs::path(".accounts").append(account_no));
        file << name << "\n" << 0.00;
        file.close();
        return "\nAccount " + account_no + " created for " + name;
    }

    string close_account(string account_no) {
        if (account_exist(account_no)) {
            fs::remove(fs::path(".accounts").append(account_no));
            return "\nAccount closed successfully!";
        }
        return "\nAccount does not exist";
    }

    string modify_account(string account_no, string new_name) {
        if (account_exist(account_no)) {
            string name;
            float balance;
            ifstream ifile(fs::path(".accounts").append(account_no));
            ifile >> name >> balance;
            ifile.close();
            ofstream ofile(fs::path(".accounts").append(account_no));
            cout << name << " " << balance;
            ofile << new_name << "\n" << balance;
            ofile.close();
            return "\n" + name + " changed to " + new_name + " successfully!";
        }
        return "\nAccount does not exist!";
    }
}