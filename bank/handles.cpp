#include <iostream>
#include "services.hpp"

namespace handles {
    string create(short option) {
        string name;
        cout << "\nCreating new account...";
        cout << "\nEnter account holder's name : ";
        cin >> name;
        return  services::create_new_account(name);
    }

    string modify(short option) {
        string account_no, new_name;
        cout << "\nModifying account..."
            << "\nEnter account no : ";
        cin >> account_no;
        cout << "Enter new name to replace : ";
        cin >> new_name;
        return services::modify_account(account_no, new_name);
    }

    string close_or_enquire(short option) {
        string account_no;
        const string action = option == 2 ? "Closing an account..." : "Enquiring balance...";
        cout << "\n" << action;
        cout << "\nEnter account number : ";
        cin >> account_no;
        const string message = option == 2 ? services::close_account(account_no) : services::enquire_balance(account_no);
        return message;
    }

    string deposite_or_withdraw(short option) {
        string account_no;
        float amount;
        const string action = option == 5 ? "Depositing" : "Withdrawing";
        cout << "\n" << action << " money..."
            << "\nEnter account no : ";
        cin >> account_no;
        cout << "Enter amount : ";
        cin >> amount;
        const float final_amount = option == 5 ? amount : -amount;
        return services::deposite_money(account_no, final_amount);
    }
}