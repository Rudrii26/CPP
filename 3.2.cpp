//3.2
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



// #include<iostream>
// using namespace std;
// class sum{
//     int total = 0;
//     int max = 0;
//     public:
//     int recursive(int a[], int x)
//     {
//         if(x == 0){
//             return 0;
//         }
//         return a[x-1] + recursive(a, x-1);
//     }

//     int Max(int a[], int x)
//     {
//         if(x == 1)
//         {
//             return a[0];
//         }
//         int m = Max(a , x - 1);

//         if(a[x-1] > m)
//             return a[x-1];
//         else
//             return m;
//     }

//     int iterative(int a[], int x)
//     {
//         for(int i=0; i<x; i++)
//         {
//             total+=a[i];
//         }
//         cout<<"Total: "<<total<<endl;

//         for(int j=0; j<x; j++){
//             if(a[j]>max){
//                 max = a[j];
//             }
//         }
//         cout<< "Max using iterative: "<<max<<endl;
//         return total;
//     }
// };
// int main()
// {
//     int n;
//     sum a;
//     cout<<"Enter the Number of elements: ";
//     cin>>n;

//     int *s = (int *)malloc(sizeof(int)*n);
//     for(int i=0; i<n; i++)
//     {
//         cout<<"Enter "<<i+1 <<"th Element: ";
//         cin>>s[i];;
//     }
//     a.iterative(s, n);
//     cout<<"Recursion: "<<a.recursive(s, n); 
//     cout<<endl;
//     cout<<"Maximum element using Recursion: "<<a.Max(s, n);                                                                                                       
// }