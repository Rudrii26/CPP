// 8.2_25CS027
#include<iostream>
#include<math.h>
using namespace std;

class NegativeNumberException {
public:
    void message() {
        cout << "Error: Negative number not allowed." << endl;
    }
};

int main() {
    int size;
    cout << "How many numbers do you want to enter? ";
    cin >> size;

    for(int i = 0; i < size; i++) {
        int num;
        try {
            cin >> num;

            if(num < 0) {
                throw NegativeNumberException();
            }
            else {
                cout << sqrt(num) << endl;
            }
        }
        catch(NegativeNumberException &e) {
            cout << "Error detected!" << endl;
            e.message();
        }
    }

    return 0;
}