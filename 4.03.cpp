#include<iostream>
using namespace std;

int main(){

    int m, n;

    cout<<"Enter the size of array 1: ";
    cin>>m;
    cout<<"Enter the size of array 2: ";
    cin>>n;

    int *a1 = new int[m];
    int *a2 = new int[n];
    int *a = new int[m+n];

    cout<<"THE INPUTS MUST BE SORTED!"<<endl;
    cout<<"Enter the elements of array1: ";
    
    for(int i=0; i<m; i++){
        cin>>a1[i];
    }

    cout<<"Enter the elements of array2: ";
    
    for(int i=0; i<n; i++){
        cin>>a2[i];
    }

        int i=0, j=0, k=0;
        while(i<m && j<n){
            if(a1[i]<=a2[j]){
                a[k++]=a1[i++];
            }
            else{
                a[k++]=a2[j++];
            }
        }
        while(j<m){
            a[k]=a2[j];
            k++;
            j++;
        }
            while(i<m){
            a[k]=a1[i];
            k++;
            i++;
        }

        for(int i=0; i<k; i++){
            cout<<a[i];
        }

    return 0;
}