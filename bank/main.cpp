#include <iostream>
#include "services.hpp"
#include "helps.hpp"

using namespace std;

string handle_create(short);
string hadle_modify(short);
string handle_close_or_enquire(short);
string handle_deposite_or_withdraw(short);

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

    if (option < 1 || option > 6)
        return EXIT_FAILURE;
    if (option == 1)
        cout << handle_create(option);
    if (option == 3)
        cout << handle_modify(option);
    if (option == 2 || option == 4)
        cout << handle_close_or_enquire(option);
    if (option == 5 || option == 6)
        cout << handle_deposite_or_withdraw(option);

    return EXIT_SUCCESS;
    cout << "\n";
}

string handle_create(short option) {
    string name;
    cout << "\nCreating new account...";
    cout << "\nEnter account holder's name : ";
    cin >> name;
    return  services::create_new_account(name);
}

string handle_modify(short option) {
    string account_no, new_name;
    cout << "\nModifying account..."
        << "\nEnter account no : ";
    cin >> account_no;
    cout << "Enter new name to replace : ";
    cin >> new_name;
    return services::modify_account(account_no, new_name);
}

string handle_close_or_enquire(short option) {
    string account_no;
    const string action = option == 2 ? "Closing an account..." : "Enquiring balance...";
    cout << "\n" << action;
    cout << "\nEnter account number : ";
    cin >> account_no;
    const string message = option == 2 ? services::close_account(account_no) : services::enquire_balance(account_no);
    return message;
}

string handle_deposite_or_withdraw(short option) {
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