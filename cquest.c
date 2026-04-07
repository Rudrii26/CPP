#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Account {
private:
    int accountNumber;
    string accountHolderName;
    double balance;
    static int totalAccounts;

public:
    Account(int accNo, string name, double bal) {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
        totalAccounts++;
    }

    // Getter for account number
    int getAccountNumber() const {
        return accountNumber;
    }

    // Static function to get total accounts
    static int getTotalAccounts() {
        return totalAccounts;
    }

    // Display account details
    void display() const {
        cout << "\n--- Account Summary ---\n";
        cout << "Account Number : " << accountNumber << endl;
        cout << "Account Holder : " << accountHolderName << endl;
        cout << "Current Balance: " << balance << endl;
    }

    // Update account holder name
    void updateName(string newName) {
        accountHolderName = newName;
    }

    // Transfer money
    bool transfer(Account &receiver, double amount) {
        if (amount <= 0) {
            cout << "Invalid amount!\n";
            return false;
        }

        if (balance < amount) {
            cout << "Insufficient balance!\n";
            return false;
        }

        balance -= amount;
        receiver.balance += amount;
        cout << "Transfer successful!\n";
        return true;
    }
};

// Initialize static member
int Account::totalAccounts = 0;


// Function to find account by account number
Account* findAccount(vector<Account*> &accounts, int accNo) {
    for (auto acc : accounts) {
        if (acc->getAccountNumber() == accNo) {
            return acc;
        }
    }
    return nullptr;
}


int main() {
    vector<Account*> accounts;
    int choice;

    do {
        cout << "\n===== Community Bank System =====\n";
        cout << "1. Add Account\n";
        cout << "2. Transfer Money\n";
        cout << "3. Display Account\n";
        cout << "4. Update Account Name\n";
        cout << "5. Show Total Accounts\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int accNo;
            string name;
            double bal;

            cout << "Enter Account Number: ";
            cin >> accNo;
            cin.ignore();

            cout << "Enter Account Holder Name: ";
            getline(cin, name);

            cout << "Enter Initial Balance: ";
            cin >> bal;

            accounts.push_back(new Account(accNo, name, bal));
            cout << "Account created successfully!\n";
        }

        else if (choice == 2) {
            int senderAcc, receiverAcc;
            double amount;

            cout << "Enter Sender Account Number: ";
            cin >> senderAcc;

            cout << "Enter Receiver Account Number: ";
            cin >> receiverAcc;

            cout << "Enter Amount to Transfer: ";
            cin >> amount;

            Account* sender = findAccount(accounts, senderAcc);
            Account* receiver = findAccount(accounts, receiverAcc);

            if (sender && receiver) {
                sender->transfer(*receiver, amount);
            } else {
                cout << "One or both accounts not found!\n";
            }
        }

        else if (choice == 3) {
            int accNo;
            cout << "Enter Account Number: ";
            cin >> accNo;

            Account* acc = findAccount(accounts, accNo);
            if (acc) {
                acc->display();
            } else {
                cout << "Account not found!\n";
            }
        }

        else if (choice == 4) {
            int accNo;
            string newName;

            cout << "Enter Account Number: ";
            cin >> accNo;
            cin.ignore();

            Account* acc = findAccount(accounts, accNo);

            if (acc) {
                cout << "Enter New Name: ";
                getline(cin, newName);
                acc->updateName(newName);
                cout << "Name updated successfully!\n";
            } else {
                cout << "Account not found!\n";
            }
        }

        else if (choice == 5) {
            cout << "Total Accounts Created: "
                 << Account::getTotalAccounts() << endl;
        }

        else if (choice == 6) {
            cout << "Exiting system...\n";
        }

        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);


    // Free dynamically allocated memory
    for (auto acc : accounts) {
        delete acc;
    }

    return 0;
}