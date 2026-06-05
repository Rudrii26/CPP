//3.4_25CS027
#include<iostream>
using namespace std;

template<class T>
void display(T arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

template<class T>
void reverse(T arr[], int n){
    T temp;
    for(int i=0; i<n/2; i++){
        temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
    cout<<"Reversed array: "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

template<class T>
void max(T arr[], int n){
    T m = arr[0];
    for(int i=0; i<n; i++){
        if(arr[i] > m){
            m = arr[i];
        }
    }
    cout<<"Maximum: "<<m<<endl;
}

int main(){
    int n;
    cout<<"Enter the size of an array: ";
    cin>>n;

    int *arr = new int[n];
    cout<<"Enter the element of an array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    display(arr, n);
    reverse(arr, n);
    max(arr, n);
    return 0;
}