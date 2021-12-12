#include <iostream>
#include "handles.hpp"
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