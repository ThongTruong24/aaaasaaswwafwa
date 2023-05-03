/*
 * File: exercise8.cpp
 * Author: Thong Truong
 * Date: 02/01/2003
 * Description: Create a bank account class with the account number, account name,
 * accounts and balances, and methods for withdrawing, depositing and checking balances
 * in accounts
 */

#include<iostream>
#include<string>

using namespace std;

class VietcomBank {
    private:
        int ID;
        string NAME;
        int ACCOUNTBALANCE;
    public:
        VietcomBank(int id = 0, string name = NULL, int accountBalance = 0);
        void enterID();
        void withdrawMoney();
        void addMoney();
        void showInformation();
        
};

VietcomBank::VietcomBank (int id, string name, int accountBalance) {
    this->ID = id;
    this->NAME = name;
    this->ACCOUNTBALANCE = accountBalance;
}

/* 
 * Function: VietcomBank::enterID()
 * Description: Enter ID and select key to go to other functions
 */
void VietcomBank::enterID () {

    int id = 0;
    int keyboard = 0;
    cout << "Please enter yout ID: "; cin >> id;
    if (id == this->ID) {
        
        againKeyBoard:
        cout << "1: Withdraw money\n2: Add money\n0: Exit\nSelect key: "; cin >> keyboard;        
        if(keyboard == 1) withdrawMoney();
        else if(keyboard == 2) addMoney();
        else if(keyboard == 0) return;
        else {
            cout << "Invalid input key. Please re-enter\n";
            goto againKeyBoard;
        }

    } else cout << "ID dose not exist";
}

/* 
 * Function: VietcomBank::withdrawMoney()
 * Description: Withdraw money from your account by entering from the keyboard
 */
void VietcomBank::withdrawMoney () {
    int money = 0;
    cout << "Amount you want to withdraw: "; cin >> money;
    this->ACCOUNTBALANCE = this->ACCOUNTBALANCE - money;
    showInformation();
}

/* 
 * Function: VietcomBank::addMoney()
 * Description: Add the amount to the account by typing in the keyboard
 */
void VietcomBank::addMoney () {
    int money = 0;
    cout << "Enter the amount you want to add: "; cin >> money;
    this->ACCOUNTBALANCE = this->ACCOUNTBALANCE + money;
    showInformation();
}

/* Description: Print information to the screen */
void VietcomBank::showInformation () {

    cout << "\nYour information:";
    cout << "\nID: " << this->ID
         << "\nName: " << this->NAME
         << "\nAccount balance: " << this->ACCOUNTBALANCE << " dong";

}

int main() {

    VietcomBank vietcomBank(2114, "Thong Truong", 100000);
    vietcomBank.enterID();

}