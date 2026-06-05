// 8.3_25CS027
#include<iostream>
#include<string>
using namespace std;

string logs[100];
int logIndex = 0;

void addLog(string msg) {
    if (logIndex < 100)
        logs[logIndex++] = msg;
}

class InsufficientFunds {};
class InvalidAmount {};

class BankAccount {
private:
    double balance;

public:
    BankAccount(double b) {
        balance = b;
        addLog("BankAccount constructor called");
    }

    void deposit(double amount) {
        addLog("Entered deposit()");
        
        if (amount <= 0) {
            addLog("Invalid deposit amount");
            throw InvalidAmount();
        }

        balance += amount;
        addLog("Deposit successful");
        addLog("Exiting deposit()");
    }

    void withdraw(double amount) {
        addLog("Entered withdraw()");
        
        if (amount <= 0) {
            addLog("Invalid withdraw amount");
            throw InvalidAmount();
        }

        if (amount > balance) {
            addLog("Insufficient balance");
            throw InsufficientFunds();
        }

        balance -= amount;
        addLog("Withdraw successful");
        addLog("Exiting withdraw()");
    }

    double getBalance() {
        return balance;
    }
};

void processWithdraw(BankAccount &acc, double amt) {
    addLog("Entered processWithdraw()");
    acc.withdraw(amt);
    addLog("Exiting processWithdraw()");
}

void performTransaction(BankAccount &acc, double amt) {
    addLog("Entered performTransaction()");
    processWithdraw(acc, amt);
    addLog("Exiting performTransaction()");
}

int main() {
    BankAccount acc(1000);

    try {
        addLog("Transaction started");
        performTransaction(acc, 1500);
        addLog("Transaction completed");
    }
    catch (InsufficientFunds &) {
        addLog("Exception caught: Insufficient Funds");
    }
    catch (InvalidAmount &) {
        addLog("Exception caught: Invalid Amount");
    }

    cout << "\nTransaction Logs :\n";
    for (int i = 0; i < logIndex; i++) {
        cout << logs[i] << endl;
    }

    cout << "\nFinal Balance: " << acc.getBalance() << endl;

    return 0;
}