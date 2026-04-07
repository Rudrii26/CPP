#include <iostream>
using namespace std;

class DynamicArray{
private:
    int *data;
    int size;
    int capacity;

public:
    DynamicArray(){
        size = 0;
        capacity = 0;
        data = nullptr;
    }

    void insert(int x){
        if(capacity == size){
            resize();
        }
        data[size++] = x;
    }

    void resize(){
        if(capacity == 0){
            capacity = 1;
        }
        else{
            capacity = capacity * 2;
        }

        int *newData = new int[capacity];

        for(int i = 0; i < size; i++){
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
    }
    void Delete(int n){
        for(int i=n-1; i<size-1; i++){
            data[i] = data[i+1];
        }
        size--;
    }
    void print(){
    for(int i = 0; i < size; i++){
        cout << data[i] << " ";
    }
    cout << endl;
}
};

int main(){
    DynamicArray d;
    d.insert(15);
    d.insert(26);
    d.insert(28);
    d.insert(10);
    d.print();
    d.Delete(2);
    d.print();
}