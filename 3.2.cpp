//3.2_25CS027
#include<iostream>
using namespace std;

class Sum {
public:

    // Recursive Sum
    int recursive(int a[], int n) {
        if(n == 0)          // Base case
            return 0;

        return a[n-1] + recursive(a, n-1);  // Recursive case
    }

    // Iterative Sum
    int iterative(int a[], int n) {
        int total = 0;

        for(int i = 0; i < n; i++) {
            total += a[i];
        }

        return total;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int* arr = new int[n];

    for(int i = 0; i < n; i++) {
        cout << "Enter element " << i+1 << ": ";
        cin >> arr[i];
    }

    Sum obj;

    cout << "\nIterative Sum: " << obj.iterative(arr, n);
    cout << "\nRecursive Sum: " << obj.recursive(arr, n);

    delete[] arr;

    return 0;
}

