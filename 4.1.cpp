#include<iostream>
using namespace std;

void insert(int a[], int n){
    int x, m;
    x = 2*n;
    int *arr=new int[x];

    cout<<"How many elementws do you want to insert? ";
    cin>>m;

    for(int i=0; i<n; i++){
        arr[i]=a[i];
    }
    for(int i=n; i<m; i++){
        cin>>arr[i];
    }

    for(int i=0; i<n+m; i++){
        cout<<arr[i];
    }
}

int main(){
    int n;
    char reply;
    cout<<"Enter the size of an array: ";
    cin>>n;

    int *a=new int[n];

    for(int i=0; i<n; i++){
        cout<<"Enter the elements: ";
        cin>>a[i];
    }
    cout<<"Do you want to insert and element in the array? (Y or N): ";
    cin>>reply;
    if(reply=='Y'){
        insert(a, n);
    }
    return 0;
}