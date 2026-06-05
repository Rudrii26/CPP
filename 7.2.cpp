//7.2_25CS027
#include<iostream>
using namespace std;

class complex{
    private:
    int real, imaginary;

    public:
    complex(int a=0, int b=0){
        real = a;
        imaginary = b;
    }
    complex operator+(complex c){
        complex temp;
        temp.real = real + c.real;
        temp.imaginary = imaginary + c.imaginary;
        return temp;
    }
    complex operator-(complex c){
        complex temp;
        temp.real = real - c.real;
        temp.imaginary = imaginary - c.imaginary;
        return temp;
    }
    void display(){
        cout<<real <<"+ "<<imaginary<<"i"<<endl;
    }
};
int main(){
    complex c1(2, 4), c2(1, 3);
    complex c3, c4;

    c3 = c1 + c2;
    c4 = c1 - c2;

    cout<<"Sum of two complex numbers: "<<endl;
    c3.display();

    cout<<"Difference of two complex numbers: "<<endl;
    c4.display();
    return 0;
}