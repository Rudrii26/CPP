//3.5_25CS027
#include<iostream>
using namespace std;

class superDigit{
    private:
    string n;
    int k;

    public:
    superDigit(){
        cout<<"Enter n: ";
        cin>>n;
        cout<<"Enter k: ";
        cin>>k;
    }

    long long calculate(){
        long long sum = 0;

        for(int i = 0; i < n.length(); i++){
            sum += n[i] - '0';
        }

        return sum * k;
    }

    int digitSuper(long long num){
        if(num < 10)
            return num;

        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }

        return digitSuper(sum);
    }
};

int main(){
    superDigit s;

    long long sum = s.calculate();

    cout << s.digitSuper(sum);
}