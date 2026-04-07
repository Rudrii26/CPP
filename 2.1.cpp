//2.1_25CS027
#include<iostream>
using namespace std;

class rectangle{
    float len;
    float wid;

    public:
    rectangle(float l, float w){
        if(l > 0 && w > 0){
        len = l;
        wid = w;
        }
        else{
            cout<<"Length and height can't be negative."<<endl;
        }
    }
    float area(){
        return len * wid;
    }
    float parameter(){
        return 2 * (len + wid);
    }
    bool check(){
        return len == wid;
    }
    void compare(rectangle r) {
        if(area() > r.area())
            cout << "First rectangle is larger.\n";
        else if(area() < r.area())
            cout << "Second rectangle is larger.\n";

        else
            cout << "Both rectangles have equal area.\n";
    }
    void display() {
        cout << "\nLength: " << len;
        cout << "\nWidth: " << wid;
        cout << "\nArea: " << area();
        cout << "\nPerimeter: " << parameter();

        if(check())
            cout << "\nIt is a Square.\n";
        else
            cout << "\nIt is not a Square.\n";
    }
};
int main(){
    rectangle r1(10,9);
    rectangle r2(4,4);

    r1.display();
    r2.display();

    r1.compare(r2);
    return 0;
}