#include <iostream>
#include "services.hpp"
#include "helps.hpp"

using namespace std;

int main() {
    cout << helps::get_ascii_art() << "\n";

    short option;
    cout <<
        R"(
        1)Create new account
        2)Close an account
        3)Modify an accout
        4)Enquire balance
        5)Deposit money
        6)Withdraw money

        Choose your option from above : )";
    cin >> option;

    switch (option) {
    case 1:
        //new
        return EXIT_SUCCESS;

    case 2:
        //close
        return EXIT_SUCCESS;

    case 3:
        //modify
        return EXIT_SUCCESS;

    case 4:
        //balance
        return EXIT_SUCCESS;

    case 5:
        //deposit
        return EXIT_SUCCESS;

    case 6:
        //withdraw
        return EXIT_SUCCESS;

    default:
        return EXIT_FAILURE;
    }
}