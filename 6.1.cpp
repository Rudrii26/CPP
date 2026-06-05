//6.1_25CS027
#include<iostream>
#include<vector>
#define pi 3.14
using namespace std;

class Shape{
    protected:
        double radius;
    Shape(double r){
        radius = r;
    }
};
class Circle: public Shape{
    public:
    Circle(double r): Shape(r){
        
    }
    void area(){
        double a;
        a = pi * radius * radius;
        cout<<"Area: "<<a<<endl;
    }
};

int main(){
    vector<Circle> vec;
    int size;
    double r;
    cout<<"Enter the size of an array: ";
    cin>>size;
    for(int i=0; i<size; i++){
        cout<<"Enter the radius: ";
        cin>>r;
        Circle c(r);
        vec.push_back(c);
    }
    for(int i=0; i<vec.size(); i++){
        vec[i].area();
    }
    return 0;
}