#include <iostream>
#include "services.hpp"

using namespace std;

int main() {
    string account_no;
    cout << "Enter account no>>> ";
    cin >> account_no;
    const string message = services::close_account(account_no) ? "Closed account successfully!" : "Account does not exist!";
    cout << message;
    return EXIT_SUCCESS;
}