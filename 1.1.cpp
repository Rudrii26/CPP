//1.1_25CS027
#include<iostream>
using namespace std;

class Wallet{
private: 
    int walletID;
    string userName;
    double balance;

public:
    Wallet(int id, string name, double bal){
        walletID = id;
        userName = name;
        balance = bal;
    }
    void loadMoney(double amt){
        balance+=amt;
        cout<<"Money Loaded Successfully!"<<endl;
    }
    void transferMoney(Wallet &reciever, int amt){
        if(amt <= balance){
            balance-=amt;
            reciever.balance += amt;
            cout<<"Money transfered Successfully!"<<endl;
        }
        else{
            cout<<"Insufficient Balance."<<endl;
        }
    }
    void display(){
        cout<<"Wallet ID: "<< walletID<<endl;
        cout<<"Username: "<<userName<<endl;
        cout<<"Current Balance: "<<balance<<endl;
    }
};
int main(){
    Wallet user1(101, "ABC", 100000);
    Wallet user2(102, "XYZ", 200000);

    user1.loadMoney(5000);

    user1.transferMoney(user2, 50000);

    user1.display();
    user2.display();

    return 0;
}