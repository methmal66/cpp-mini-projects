#include <iostream>
#include "services.hpp"

using namespace std;

int main() {
    string name;
    cout << "Enter account holder's name>>> ";
    cin >> name;
    cout << services::create_new_account(name);
    return EXIT_SUCCESS;
}