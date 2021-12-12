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


    switch (option) {

    case 1: {
        string name;
        cout << "\nCreating new account...";
        cout << "\nEnter account holder's name : ";
        cin >> name;
        cout << services::create_new_account(name);
        break;
    }

    case 2: {
        string account_no;
        cout << "\nClosing an account..."
            << "\nEnter account number : ";
        cin >> account_no;
        cout << services::close_account(account_no);
        break;
    }

    case 3: {
        string account_no, new_name;
        cout << "\nModifying account..."
            << "\nEnter account no : ";
        cin >> account_no;
        cout << "\nEnter new name to replace : ";
        cin >> new_name;
        cout << services::modify_account(account_no, new_name);
        break;
    }
    case 4: {
        string account_no;
        cout << "\nEnquire balance..."
            << "\nEnter account number : ";
        cin >> account_no;
        cout << services::enquire_balance(account_no);
        break;
    }
    case 5: {
        string account_no;
        float amount;
        cout << "\nDepositing money..."
            << "\nEnter account no : ";
        cin >> account_no;
        cout << "\nEnter amount : ";
        cin >> amount;
        cout << services::deposite_money(account_no, amount);
        break;
    }
    case 6: {
        string account_no;
        float amount;
        cout << "\nDepositing money..."
            << "\nEnter account no : ";
        cin >> account_no;
        cout << "\nEnter amount : ";
        cin >> amount;
        cout << services::deposite_money(account_no, -amount);
        break;
    }
    default:
        cout << "\nInvalid option!";
        break;
    }
}