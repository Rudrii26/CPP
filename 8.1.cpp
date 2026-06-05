//8.1_25CS027
#include<iostream>
using namespace std;

class division{
    private:
    int num1, num2;

    public:
    division(){

    }
    division(int n1, int n2){
        num1 = n1;
        num2 = n2;
    }

    int div(){
        cout<<"Enter the numbers: ";
        
        if(!(cin>>num1>>num2)){
            throw string("Invalid input");
        }
        else if(num2 == 0){
            throw string("Division by zero");
        }
        else{
        return num1/num2;
        }
    }
};
int main(){
    int n1, n2;
    try{
        division d;
        d.div();
    }
    catch (string &e){
        cout<<"Error detected!"<<endl<<e;
    }
    return 0;
}