#ifndef SERVICES_HPP
#define SERVICES_HPP

#include <iostream>

using namespace std;

namespace services {
    void create_new_account(string);
    void close_account(string);
    void modify_account(string, string);
    void enquire_balance(string);
    void deposite_money(string, float);
    void withdraw_money(string, float);
}

#endif
