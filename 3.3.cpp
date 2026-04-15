//3.3_25CS027
#include<iostream>
using namespace std;

class bank{
    int ACNo;
    string Holder;
    int currentBalance;
    static int totalAC;

public:
    bank(){
        ACNo = 0;
        Holder = "None";
        currentBalance = 0;
    }

    void input(){
        cout<<"Enter Account Number: ";
        cin>>ACNo;
        cout<<"Enter Holder Name: ";
        cin>>Holder;
        cout<<"Enter Balance: ";
        cin>>currentBalance;
        totalAC++;
    }

    void display(){
        cout<<"\nAccount No: "<<ACNo;
        cout<<"\nHolder Name: "<<Holder;
        cout<<"\nBalance: "<<currentBalance<<endl;
    }

    static void showTotal(){
        cout<<"\nTotal Accounts: "<<totalAC<<endl;
    }

    static void transfer(bank b[], int n, int sender, int receiver, int amt){
        int sIndex = -1, rIndex = -1;

        for(int i=0; i<n; i++){
            if(b[i].ACNo == sender)
                sIndex = i;
            if(b[i].ACNo == receiver)
                rIndex = i;
        }

        if(sIndex == -1 || rIndex == -1){
            cout<<"Invalid Account Number!\n";
            return;
        }

        if(sender == receiver){
            cout<<"Cannot transfer to same account!\n";
            return;
        }

        if(b[sIndex].currentBalance < amt){
            cout<<"Insufficient Balance!\n";
            return;
        }

        b[sIndex].currentBalance -= amt;
        b[rIndex].currentBalance += amt;

        cout<<"\nTransfer Successful!\n";
    }
};

int bank::totalAC = 0;

int main(){
    int n;
    cout<<"Enter number of accounts: ";
    cin>>n;

    bank *b = new bank[n];

    for(int i=0; i<n; i++){
        cout<<"\nEnter details for account "<<i+1<<endl;
        b[i].input();
    }

    cout<<"\n--- Before Transfer ---\n";
    for(int i=0; i<n; i++){
        b[i].display();
    }

    int s, r, amt;
    cout<<"\nEnter Sender AC No: ";
    cin>>s;
    cout<<"Enter Receiver AC No: ";
    cin>>r;
    cout<<"Enter Amount: ";
    cin>>amt;

    bank::transfer(b, n, s, r, amt);

    cout<<"\n--- After Transfer ---\n";
    for(int i=0; i<n; i++){
        b[i].display();
    }

    bank::showTotal();

    delete[] b;
    return 0;
}
