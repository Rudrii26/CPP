//6.3_25CS027
#include<iostream>
using namespace std;

class Fuel{
    protected:
    string type;

    public:
    Fuel(string t){
        type = t;
    }
};
class Brand{
    protected:
    string model;

    public:
    Brand(string m){
        model = m;
    }
};
class Car: public Fuel, public Brand{
    public:
    Car(string t, string m): Fuel(t), Brand(m){}
    
    void display(){
        cout<<"Car model: "<<model<<endl;
        cout<<"Fuel type: "<<type<<endl;
    }
};
int main(){
    Car c("Petrol", "Range rover");
    c.display();
    return 0;
}