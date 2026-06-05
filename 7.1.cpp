//7.1_25CS027
#include<iostream>
using namespace std;

class calculator{
    public:
    int add(int a, int b){
        return a + b;
    }
    float add(float a, float b){
        return a + b;
    }
    float add(float a, int b){
        return a + b;
    }
};
int main(){
    calculator c;
    cout<<c.add(15, 26)<<endl;
    cout<<c.add(2.8f, 0.4f)<<endl;
    cout<<c.add(0.9f, 10)<<endl;

    return 0;
}