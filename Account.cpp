#include <iostream>
#include <fstream>
#include "Account.h"
using namespace std;

//ceate Account
void Account::createAccount() {

    cout << "Enter Account Number: ";
    cin >> accNo;

    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(name, 50);

    cout << "Set PIN: ";
    cin >> pin;

    cout << "Enter Initial Balance: ";
    cin >> balance;

}


//deposit amount
void Account::deposit(double amt) {
    balance += amt;
}


//withdraw amount
void Account::withdraw(double amt) {
    if(amt <= balance) {
        balance -= amt;
    }
    else {
        cout << "Insufficient Balance\n";
    }
}


void Account::showAccount() const {
    cout << "\nAcc No: " << accNo
         << "\nName: " << name
         << "\nBalance: " << balance << endl;
}


int Account::getAccNo() const {
    return accNo;
}

int Account::getPin() const {
    return pin;
}

double Account::getBalance() const {
    return balance;
}
