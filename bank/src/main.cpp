#include <iostream>
#include <string.h>
#include "handles.hpp"
#include "helps.hpp"
#include "CLI11.hpp"

using namespace std;

int main(int argc, char** argv) {
    CLI::App app{ "Simple program to demonstrate the basic operations of a bank" };
    app.require_subcommand(1);

    auto create = app.add_subcommand("create", "Create an account");

    auto close = app.add_subcommand("close", "Close an existing account");
    string defaultAccountNo = "00000000";
    close->add_option("-n,--account-no", defaultAccountNo, "Account number you want to do the transaction with");

    auto modify = app.add_subcommand("modify", "Modify the username of an existing account");
    string defaultUsername = "Username";
    modify->add_option("-n,--account-no", defaultAccountNo, "Account number you want change the username");
    modify->add_option("-u,--username", "New username of the account");

    auto enquire = app.add_subcommand("enquire", "Enquire account balance");
    enquire->add_option("-n,--account-no", defaultAccountNo, "Account number you want to check the balance");

    auto deposite = app.add_subcommand("deposite", "Deposite money to bank account");
    deposite->add_option("-n,--account-no", defaultAccountNo, "Account number you want to deposite money");
    deposite->add_option("-a,--amount", "Amount to be deposited");

    auto withdraw = app.add_subcommand("withdraw", "withdraw money from bank account");
    withdraw->add_option("-n,--account-no", defaultAccountNo, "Account number you want to withdraw money");
    withdraw->add_option("-a,--amount", "Amount to be withdrawed");

    short option;
    cout << "\n1)Create new account"
        << "\n2)Close an account"
        << "\n3)Modify an account"
        << "\n4)Enquire balance"
        << "\n5)Deposit money"
        << "\n6)Withdraw money";
    cout << "\n\nChoose your option from above : ";
    cin >> option;

    if (option == 1)
        cout << handles::create(option);
    if (option == 3)
        cout << handles::modify(option);
    if (option == 2 || option == 4)
        cout << handles::close_or_enquire(option);
    if (option == 5 || option == 6)
        cout << handles::deposite_or_withdraw(option);

    if (option < 1 || option > 6)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
    cout << "\n";
}