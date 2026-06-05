//7.3_25CS027
#include<iostream>
using namespace std;

class celcius{
    private:
    double temp;
    public:
    celcius(double t){
        temp = t;
    }

    double getFahrenheit(){
        double f;
        f = (9*(temp)/5)+ 32;
        return f;
    }
    bool operator == (celcius c){
        if(temp == c.temp){
            return true;
        }
        else{
            return false;
        }
    }
};
class fahrenheit{
    private:
    double temp;

    public:
    fahrenheit(double t){
        temp = t;
    }

    double getCelcius(){
        double c;
        c = (temp - 32) * 5/9;
        return c;
    }
    bool operator == (fahrenheit f){
        if(temp == f.temp){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    celcius c1(-40);
    cout << c1.getFahrenheit()<<endl;
    celcius c2(31);
    cout << c2.getFahrenheit()<<endl;
    cout<<(c1==c2)<<endl;
    fahrenheit f1(95);
    cout << f1.getCelcius()<<endl;
    fahrenheit f2(95);
    cout << f2.getCelcius()<<endl;
    cout<<(f1==f2)<<endl;
    return 0;
}