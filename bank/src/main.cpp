#include <iostream>
#include <string.h>
#include "services.hpp"
#include "helps.hpp"
#include "CLI11.hpp"

using namespace std;

int main(int argc, char** argv) {
    CLI::App app{ "Simple program to demonstrate the basic operations of a bank" };
    app.require_subcommand(1);

    auto create = app.add_subcommand("create", "Create an account");
    string username;
    create->add_option("-u,--username", username, "Username of the new account");
    create->callback([&]() {
        services::create_new_account(username);
        });

    auto close = app.add_subcommand("close", "Close an existing account");
    string accountNo;
    close->add_option("-n,--account-no", accountNo, "Account number you want to do the transaction with");
    close->callback([&]() {
        try {
            services::close_account(accountNo);
        }
        catch (exception& e) {
            cerr << "An error occured " << e.what() << endl;
        }
        });

    auto modify = app.add_subcommand("modify", "Modify the username of an existing account");
    modify->add_option("-n,--account-no", accountNo, "Account number you want change the username");
    modify->add_option("-u,--username", username, "New username of the account");
    modify->callback([&]() {
        try {
            services::modify_account(accountNo, username);
        }
        catch (exception& e) {
            cerr << "An error occured " << e.what() << endl;
        }
        });

    auto enquire = app.add_subcommand("enquire", "Enquire account balance");
    enquire->add_option("-n,--account-no", accountNo, "Account number you want to check the balance");
    enquire->callback([&]() {
        try {

            services::enquire_balance(accountNo);
        }
        catch (exception& e) {
            cerr << "An error occured " << e.what() << endl;
        }
        });

    auto deposite = app.add_subcommand("deposite", "Deposite money to bank account");
    int amount;
    deposite->add_option("-n,--account-no", accountNo, "Account number you want to deposite money");
    deposite->add_option("-a,--amount", amount, "Amount to be deposited");
    deposite->callback([&]() {
        try {
            services::deposite_money(accountNo, amount);
        }
        catch (exception& e) {
            cerr << "An error occured " << e.what() << endl;
        }
        });

    auto withdraw = app.add_subcommand("withdraw", "withdraw money from bank account");
    withdraw->add_option("-n,--account-no", accountNo, "Account number you want to withdraw money");
    withdraw->add_option("-a,--amount", amount, "Amount to be withddrawed");
    withdraw->callback([&]() {
        try {
            services::withdraw_money(accountNo, amount);
        }
        catch (exception& e) {
            cerr << "An error occured " << e.what() << endl;
        }
        });

    auto help = app.add_subcommand("help")->silent();
    help->parse_complete_callback([]() {
        throw CLI::CallForHelp();
        });

    CLI11_PARSE(app, argc, argv);
}