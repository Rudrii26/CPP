//2.4_25CS027
#include<iostream>
using namespace std;

class Item {
private:
    int itemID;
    string itemName;
    double price;
    int quantity;

public:

    // Default Constructor
    Item() {
        itemID = 0;
        itemName = "None";
        price = 0;
        quantity = 0; 
    }

    // Parameterized Constructor
    Item(int id, string name, double p, int q) {
        itemID = id;
        itemName = name;
        price = (p >= 0) ? p : 0;
        quantity = (q >= 0) ? q : 0;
    }

    void addStock(int q) {
        if(q > 0)
            quantity += q;
        else
            cout << "Invalid stock amount!\n";
    }

    void sellItem(int q) {
        if(q <= 0)
            cout << "Invalid sale quantity!\n";
        else if(q > quantity)
            cout << "Not enough stock available!\n";
        else
            quantity -= q;
    }

    void display() {
        cout << "\nItem ID: " << itemID;
        cout << "\nItem Name: " << itemName;
        cout << "\nPrice: " << price;
        cout << "\nQuantity: " << quantity;
        cout << "\n----------------------\n";
    }
};

int main() {

    // Multiple items (Product catalog)
    Item items[2] = {
        Item(1, "Laptop", 80000, 10),
        Item(2, "Mouse", 1500, 25)
    };

    // Operations
    items[0].sellItem(3);
    items[1].addStock(10);
    items[1].sellItem(40);   // Edge case

    // Display all items
    for(int i = 0; i < 2; i++) {
        items[i].display();
    }

    return 0;
}
