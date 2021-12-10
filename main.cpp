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