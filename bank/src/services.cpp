#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include "helps.hpp"

using namespace std;

namespace services {

    string create_new_account(string name) {
        string account_no;
        do
            account_no = helps::generate_random_account_no();
        while (helps::account_exist(account_no));
        ofstream file(helps::find_appdata_path().append(account_no));
        cout << helps::find_appdata_path();
        file << name << "\n" << 0.00;
        file.close();
        return "Account " + account_no + " created for " + name;
    }

    string close_account(string account_no) {
        if (helps::account_exist(account_no)) {
            filesystem::remove(helps::find_appdata_path().append(account_no));
            return "Success!";
        }
        return "Account does not exist";
    }

    string modify_account(string account_no, string new_name) {
        if (helps::account_exist(account_no)) {
            string name;
            float balance;
            ifstream ifile(helps::find_appdata_path().append(account_no));
            ifile >> name >> balance;
            ifile.close();
            ofstream ofile(helps::find_appdata_path().append(account_no));
            ofile << new_name << "\n" << balance;
            ofile.close();
            return "Success!";
        }
        return "Account does not exist!";
    }

    string enquire_balance(string account_no) {
        if (helps::account_exist(account_no)) {
            string name;
            float balance;
            ifstream file(helps::find_appdata_path().append(account_no));
            file >> name >> balance;
            file.close();
            const string str_balance = to_string(balance);
            return str_balance.substr(0, str_balance.length() - 4);
        }
        return "Account does not exist!";
    }

    string deposite_money(string account_no, float amount) {
        if (helps::account_exist(account_no)) {
            string name;
            float balance;
            ifstream ifile(helps::find_appdata_path().append(account_no));
            ifile >> name >> balance;
            ifile.close();
            float new_balance = balance + amount;
            ofstream ofile(helps::find_appdata_path().append(account_no));
            ofile.precision(2);
            ofile << name << "\n" << fixed << new_balance;
            ofile.close();
            return "Success!";
        }
        return "Account does not exist!";
    }

    //reuse deposite_money function without reinventing the wheel. Its also make the api more abstract    
    string withdraw_money(string account_no, float amount) {
        return deposite_money(account_no, -amount);
    }
}