/*5. Write a C++ program to implement a class called BankAccount that has private member variables for account number and balance. Include member functions to deposit and withdraw money from the account.*/

#include <iostream>
using namespace std;

class BankAccount {
private:
    double account_number;
    double balance;
public:
    void deposit(const int d){
        balance += d;
    }
    void withdraw(const int w){
        if (balance >= w){
            balance -= w;
        }
        else { cout << "Insufficient balance."; }
    }
    double getBalance(){
        return balance;
    }
};


int main() {
    BankAccount acc1;
    acc1.deposit(1000);
    acc1.withdraw(1500);
    cout << "Acc1: " << endl << "balance: " << acc1.getBalance() << endl;

    return 0;
}
