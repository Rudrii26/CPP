#include<iostream>
using namespace std;

class Point{
    public:
    int x, y;

    public:
    Point(int X, int Y){
        x = X;
        y = Y;
    }
    int getx(){
        return this->x;
    }
    int gety(){
        return this->y;
    }
    Point& move(int dx, int dy){
        this->x += dx;
        this->y += dy;

        return *this;
    }
    void reset(){
        this->move(-getx(), -gety());
    }
};

    // void reset(Point p){

    //     p.move(-p.getx(), -p.gety());
    // }

int main(){
    Point p(1,2);
    p.getx();
    cout<<p.x;
    p.gety();
    cout<<p.y<<endl;
    p.move(2,2);
    cout<<p.x<<" "<<p.y<<endl;
    p.reset();
    cout<<p.x<<" "<<p.y<<endl;
    
    return 0;
}