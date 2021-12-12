#include <iostream>
#include <filesystem>
#include <fstream>
#include <random>
#include <string>

using namespace std;

bool account_exist(string account_no) {
    for (const auto& file : filesystem::directory_iterator(".accounts"))
        if (account_no == file.path().filename())
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

        ofstream file(filesystem::path(".accounts").append(account_no));
        file << name << "\n" << 0.00;
        file.close();
        return "Account " + account_no + " created for " + name;
    }

    string close_account(string account_no) {
        if (account_exist(account_no)) {
            filesystem::remove(filesystem::path(".accounts").append(account_no));
            return "Account closed successfully!";
        }
        return "Account does not exist";
    }

    string modify_account(string account_no, string new_name) {
        if (account_exist(account_no)) {
            string name;
            float balance;
            ifstream ifile(filesystem::path(".accounts").append(account_no));
            ifile >> name >> balance;
            ifile.close();
            ofstream ofile(filesystem::path(".accounts").append(account_no));
            ofile << new_name << "\n" << balance;
            ofile.close();
            return name + " changed to " + new_name + " successfully!";
        }
        return "Account does not exist!";
    }

    string enquire_balance(string account_no) {
        if (account_exist(account_no)) {
            string name;
            float balance;
            ifstream file(filesystem::path(".accounts").append(account_no));
            file >> name >> balance;
            file.close();
            const string str_balance = to_string(balance);
            return str_balance.substr(0, str_balance.length() - 4);
        }
        return "Account does not exist!";
    }

    string deposite_money(string account_no, float amount) {
        if (account_exist(account_no)) {
            string name;
            float balance;
            ifstream ifile(filesystem::path(".accounts").append(account_no));
            ifile >> name >> balance;
            ifile.close();
            float new_balance = balance + amount;
            ofstream ofile(filesystem::path(".accounts").append(account_no));
            ofile.precision(2);
            ofile << name << "\n" << fixed << new_balance;
            ofile.close();
            return "Balance successfully changed from " + to_string(balance) + " to " + to_string(new_balance) + " !";
        }
        return "Account does not exist!";
    }
}