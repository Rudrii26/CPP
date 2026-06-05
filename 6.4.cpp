//6.4_25CS027
#include<iostream>
using namespace std;

class Account{
protected:
    int acNo;
    double currentBalance;

public:
    Account(int no, double balance){
        acNo = no;
        currentBalance = balance;
    }

    void deposit(double amt){
        currentBalance += amt;
        cout<<"Deposit successful!"<<endl;
    }

    virtual void withdraw(double amt){
        if(amt <= currentBalance){
            currentBalance -= amt;
            cout<<"Withdraw successful!"<<endl;
        }
        else{
            cout<<"Insufficient balance!"<<endl;
        }
    }

    void display(){
        cout<<"Account No.: "<<acNo<<endl;
        cout<<"Current Balance: "<<currentBalance<<endl;
    }

    ~Account(){}
};

class savingAccount : public Account{
private:
    double interestRate;

public:
    savingAccount(int no, double balance, double rate) : Account(no, balance){
        interestRate = rate;
    }

    void addInterest(){
        double interest;
        interest = (currentBalance * interestRate)/100;
        currentBalance += interest;

        cout<<"Interest added: "<<interest<<endl;
    }

    ~savingAccount(){}
};

class currentAccount : public Account{
private:
    double overdraftLimit;

public:
    currentAccount(int no, double balance, double overdraft) : Account(no, balance){
        overdraftLimit = overdraft;
    }

    void withdraw(double amt){
        if(amt <= currentBalance + overdraftLimit){
            currentBalance -= amt;
            cout<<"Withdraw successful!"<<endl;
        }
        else{
            cout<<"Overdraft limit exceeded!"<<endl;
        }
    }

    ~currentAccount(){}
};

int main(){

    cout<<"Savings Account"<<endl;

    savingAccount s1(101,5000,5);

    s1.deposit(1000);
    s1.addInterest();
    s1.withdraw(2000);
    s1.display();

    cout<<endl;

    cout<<"Current Account"<<endl;

    currentAccount c1(201,3000,2000);

    c1.deposit(500);
    c1.withdraw(4000);
    c1.display();

    return 0;
}
