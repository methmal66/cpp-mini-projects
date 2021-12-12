#ifndef SERVICES_HPP
#define SERVICES_HPP

#include <iostream>

using namespace std;

bool account_exist(string);
string generate_random_account_no();

namespace services {
    string create_new_account(string);
    string close_account(string);
    string  modify_account(string, string);
    string enquire_balance(string);
    void deposite_ammount(string, float);
    void withdraw_ammount(string, float);
}

#endif
