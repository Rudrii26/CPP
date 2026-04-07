//1.2_25CS027
#include<iostream>
using namespace std;

class book{
    int bookID;
    string title;
    string author;
    int available;

public:
    void addBook(){
        cout<<"Enter Book ID: ";
        cin>>bookID;
        cout<<endl<<"Enter Book Title: ";
        cin.ignore();
        getline(cin, title);
        cout<<endl<<"Enter Book Author: ";
        getline(cin, author);
        cout<<endl<<"Enter Number of Copies: ";
        cin>>available;
    }
    void bookIssue(){
        if(available > 0){
            available--;
        cout << "Book Issued Successfully!\n";
    } else {
        cout << "No copies available!\n";
    }
    }

    void bookReturn(){
    available++;
    cout << "Book Returned Successfully!\n";
    }
    void display(){
    cout << "\nBook ID: " << bookID;
    cout << "\nTitle: " << title;
    cout << "\nAuthor: " << author;
    cout << "\nAvailable Copies: " << available << endl;
    }
};
int main(){
    book b;

    b.addBook();
    b.bookIssue();
    b.bookReturn();
    b.display();

    return 0;
}
