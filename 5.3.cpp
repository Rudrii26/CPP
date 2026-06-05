//5.3_25CS027
#include <iostream>
#include <fstream>
using namespace std;

class Inventory {
public:
    string name, search;
    int qty;
    float price;

    void addItem() {
        ofstream out("inventory.txt", ios::app);

        cout << "Enter name quantity price: ";
        cin >> name >> qty >> price;

        out << name << " " << qty << " " << price << endl;
        out.close();

        cout << "Item added\n";
    }

    void viewItems() {
        ifstream in("inventory.txt");

        if (!in) {
            cout << "File not found\n";
            return;
        }

        while (in >> name >> qty >> price) {
            cout << name << " " << qty << " " << price << endl;
        }

        in.close();
    }

    void searchItem() {
        ifstream in("inventory.txt");

        if (!in) {
            cout << "File not found\n";
            return;
        }

        cout << "Enter name to search: ";
        cin >> search;

        int found = 0;

        while (in >> name >> qty >> price) {
            if (name == search) {
                cout << name << " " << qty << " " << price << endl;
                found = 1;
            }
        }

        if (found == 0)
            cout << "Item not found\n";

        in.close();
    }
};

int main() {
    Inventory obj;

        obj.addItem();
        obj.searchItem();

    return 0;
}