#include<iostream>
using namespace std;
class bank{
    int ACNo;
    string Holder;
    int currentBalance;
    static int totalAC;

    public:
    bank()
    {
        int num = 0;
        string name = "None";
        int balance = 0;
    }
    bank(int num, string name, int balance)
    {
        ACNo = num;
        Holder = name;
        currentBalance = balance;
        totalAC++;
    }
    void display(){
        cout<<currentBalance;
    }
    void transfer(bank b1[], int num, int amt, int n)
    {
        for(int i=0; i<n; i++){
            if(b1[i].ACNo == num){
                if(amt > currentBalance){
                    cout << "Incefficient Balance!";
                }
                else{
                    b1[i].currentBalance+=amt;
                    currentBalance-=amt;
                    display();
                }
            }
        }
    }
};