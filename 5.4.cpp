//5.4_25CS027
#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

ostream& currency(ostream& os){
    return os << "$";
}

int main(){
    string Names[] = {"ABC", "PQR", "XYZ"};
    int Marks[] = {90, 80, 70};
    double Fees[] = {1000.50, 2000.75, 3000.25};

    cout<< setfill('-') << setw(50) << "-" <<endl;
    cout<<setfill(' ');
    cout<< left << setw(25)<<"Students name" <<setw(15)<<"marks" << setw(20)<<"fees" <<endl;
    cout<< setfill('-') << setw(50) << "-" <<endl;
    cout<<setfill(' ');
    
    for(int i=0; i<3; i++){
        cout<< left << setw(25) << Names[i] << setw(15) << Marks[i] << currency << fixed << setprecision(2) << Fees[i] <<endl;
    }
    cout << setfill('-') << setw(55) << '-' <<endl;
    return 0;
}