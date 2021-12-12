#include <iostream>
#include "services.hpp"
#include "helps.hpp"

using namespace std;

int main() {
    cout << helps::get_ascii_art() << "\n";

    short option;
    cout << "\n1)Create new account"
        << "\n2)Close an account"
        << "\n3)Modify an account"
        << "\n4)Enquire balance"
        << "\n5)Deposit money"
        << "\n6)Withdraw money";
    cout << "\n\nChoose your option from above : ";
    cin >> option;

    if (option == 2 || option == 4) {
        string account_no;
        const string action = option == 2 ? "Closing an account..." : "Enquiring balance...";
        cout << "\n" << action;
        cout << "\nEnter account number : ";
        cin >> account_no;
        const string message = option == 2 ? services::close_account(account_no) : services::enquire_balance(account_no);
        cout << message;
    }

    if (option == 5 || option == 6) {
        string account_no;
        float amount;
        const string action = option == 5 ? "Depositing" : "Withdrawing";
        cout << "\n" << action << " money..."
            << "\nEnter account no : ";
        cin >> account_no;
        cout << "Enter amount : ";
        cin >> amount;
        const float final_amount = option == 5 ? amount : -amount;
        cout << services::deposite_money(account_no, final_amount);
    }

    if (option == 1) {
        string name;
        cout << "\nCreating new account...";
        cout << "\nEnter account holder's name : ";
        cin >> name;
        cout << services::create_new_account(name);
    }

    if (option == 3) {
        string account_no, new_name;
        cout << "\nModifying account..."
            << "\nEnter account no : ";
        cin >> account_no;
        cout << "Enter new name to replace : ";
        cin >> new_name;
        cout << services::modify_account(account_no, new_name);
    }

    cout << "\n";
}