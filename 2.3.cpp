//2.3
#include<iostream>
using namespace std;

class SavingsAccount {
private:
    string customerName;
    int accountID;
    double balance;

public:

    // Constructor with zero balance
    SavingsAccount(string name, int id) {
        customerName = name;
        accountID = id;
        balance = 0;
    }

    // Constructor with custom balance
    SavingsAccount(string name, int id, double initialBalance) {
        customerName = name;
        accountID = id;

        if(initialBalance >= 0)
            balance = initialBalance;
        else
            balance = 0;
    }

    void deposit(double amount) {
        if(amount > 0)
            balance += amount;
        else
            cout << "Invalid deposit amount!\n";
    }

    void withdraw(double amount) {
        if(amount > balance)
            cout << "Insufficient balance!\n";
        else if(amount > 0)
            balance -= amount;
        else
            cout << "Invalid withdrawal amount!\n";
    }

    void display() {
        cout << "\nAccount Summary";
        cout << "\nName: " << customerName;
        cout << "\nAccount ID: " << accountID;
        cout << "\nBalance: " << balance;
        cout << "\n-------------------------\n";
    }
};

int main() {

    // Multiple account creation
    SavingsAccount acc1("Ali", 101);
    SavingsAccount acc2("Sara", 102, 5000);

    // Transactions
    acc1.deposit(2000);
    acc1.withdraw(500);
    acc1.withdraw(3000);   // Edge case

    acc2.deposit(1000);
    acc2.withdraw(2000);

    // Display summaries
    acc1.display();
    acc2.display();

    return 0;
}