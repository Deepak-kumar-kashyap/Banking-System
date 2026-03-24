#include <iostream>
#include <fstream>
#include "Account.h"
#include <vector>
#include <string>
using namespace std;


void userMenu(Account acc);
Account getUpdatedAccount(int accNo);
void viewTransactions(int accNo);
void transferMoney(int, int, double);
void updateAccount(Account acc);

//write account
void writeAccount(Account acc) {
    ofstream out("accounts.dat", ios::binary | ios::app);
    out.write((char*) &acc, sizeof(acc));
    out.close();
}


//login
bool login(int accNo, int pin, Account &acc) {
    ifstream in("accounts.dat", ios::binary);

    while(in.read((char*) &acc, sizeof(acc))) {
        if(acc.getAccNo() == accNo && acc.getPin() == pin) {
            return true;
        }
    }
    return false;
    
}


//update account
void updateAccount(Account acc) {
    fstream file("accounts.dat", ios::binary | ios::in | ios::out);

    Account temp;

    while(file.read((char*) &temp, sizeof(temp))) {
        if(temp.getAccNo() == acc.getAccNo()) {
            int pos = -1 * sizeof(temp);
            file.seekp(pos, ios::cur);
            file.write((char*) &acc, sizeof(acc));
            break;
        }
    }
}


void viewTransactions(int accNo) {
    ifstream file("transactions.txt");
    int a;
    string type;
    double amt;

    cout << "\n---- Transaction History ----\n";
    
    while(file >> a >> type >> amt) {
        if(a == accNo) {
            cout << type << " : " << amt << endl;
        }
    }
}


Account getUpdatedAccount(int accNo) {
    ifstream in("accounts.dat", ios::binary);
    Account acc;

    while(in.read((char*) &acc, sizeof(acc))) {
        if(acc.getAccNo() == accNo) {
            return acc;
        }
    }
    return acc;
}



//transaction history
void logTransaction(int accNo, string type, double amt) {
    ofstream file("transactions.txt", ios::app);
    file << accNo << " " << type << " " << amt << endl;
}


void transferMoney(int fromAcc, int toAcc, double amt) {
    fstream file("accounts.dat", ios::binary | ios::in | ios::out);
    Account acc;
    vector<Account> all;

    //read all accounts

    while(file.read((char*) &acc, sizeof(acc))) {
        all.push_back(acc);
    }

    file.close();

    bool found1 = false, found2 = false;

    for(auto a : all) {
        if(a.getAccNo() == fromAcc) {
            if(a.getBalance() >= amt) {
                a.withdraw(amt);
                found1 = true;
            }
        }

        if(a.getAccNo() == toAcc) {
            a.deposit(amt);
            found2 = true;
        }
    }

    //write file
    ofstream out("accounts.dat", ios::binary | ios::trunc);
    for(auto a : all) {
        out.write((char*) &a, sizeof(a));
    }

    if(found1 && found2) {
        cout << "Transfer Successful\n";
    }
    else {
        cout << "Transfer Failed\n";
    }
}



//User Menu
void userMenu(Account acc) {
    int choice;
    double amt;
    int targetAcc;

    do {
        cout << "\n\n====== USER MENU ======";
        cout << "\n1. Deposit";
        cout << "\n2. Withdraw";
        cout << "\n3. Balance Inquiry";
        cout << "\n4. Transfer Money";
        cout << "\n5. View Transactions";
        cout << "\n6. Logout";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice) {

            //Deposit
            case 1: 
                cout <<"Enter amount: ";
                cin >> amt;
                acc.deposit(amt);
                updateAccount(acc);
                acc = getUpdatedAccount(acc.getAccNo());
                logTransaction(acc.getAccNo(), "DEPOSIT", amt);
                cout << "Amount Deposited\n";
                break;

            //withdraw
            case 2:
                cout << "Enter amount: ";
                cin >> amt;
                if(amt <= acc.getBalance()) {
                    acc.withdraw(amt);
                    updateAccount(acc);
                    acc = getUpdatedAccount(acc.getAccNo());
                    logTransaction(acc.getAccNo(), "WITHDRAW", amt);
                    cout << "Amount Withdrawn\n";
                }
                else {
                    cout << "Insufficient Balance\n";
                }
                break;
            
            //Balance
            case 3:
                acc.showAccount();
                break;

            //Transfer
            case 4:
                cout << "Enter target account: ";
                cin >> targetAcc;
                cout << "Enter amount: ";
                cin >> amt;

                if(amt <= acc.getBalance()) {
                    transferMoney(acc.getAccNo(), targetAcc, amt);
                    logTransaction(acc.getAccNo(), "TRANSFER", amt);
                }
                else {
                    cout << "Insufficient Balance\n";
                }
                break;

            case 5:
                viewTransactions(acc.getAccNo());
                break;

            //Logout
            case 6:
                cout << "Logging out...\n";
                break;

            default:
            cout << "Invalid choice\n";
        }
    } while(choice != 6);
}


int main() {
    int choice;

    do {
        cout << "\n1. Create Account";
        cout << "\n2. Login";
        cout << "\n3. Exit\n";
        cin >> choice;


        switch (choice) {

            case  1: {
                Account acc;
                acc.createAccount();
                writeAccount(acc);
                break;
            }

            case 2: {
                int accNo, pin;
                Account acc;

                cout << "Enter Account No: ";
                cin >> accNo;
                cout << "Enter PIN: ";
                cin >> pin;

                if(login(accNo, pin, acc)) {
                    cout << "Login Successful\n";
                    //Call usermenu
                    userMenu(acc);
                }
                else {
                    cout << "Invalid Login\n";
                }
                break;
            }           
        }

    } while(choice != 3);
}