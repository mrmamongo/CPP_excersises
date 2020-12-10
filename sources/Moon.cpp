//
// Created by lamp on 11.12.2020.
//

#include "Moon.hpp"

Bank::Bank() {
    cout << "Welcome!\nEnter login(\"create\" if you want to create an account): ";
    string login;
    if (login == "create") {
        CreateAccount();
    }
}

void Bank::CreateAccount() {

}
