//3.1_25CS027
#include<iostream>
using namespace std;

class Employee {
private:
    string name;
    double basicSalary;
    double bonus;

public:
    Employee() {
        name = "None";
        basicSalary = 0;
        bonus = 1000;  
    }

    Employee(string n, double basic) {
        name = n;
        basicSalary = basic;
        bonus = 1000;
    }

    Employee(string n, double basic, double b) {
        name = n;
        basicSalary = basic;
        bonus = b;
    }

    inline double totalSalary() {
        return basicSalary + bonus;
    }

    void display() {
        cout << "\nEmployee Name: " << name;
        cout << "\nBasic Salary: " << basicSalary;
        cout << "\nBonus: " << bonus;
        cout << "\nTotal Salary: " << totalSalary();
    }
};

int main() {

    int n = 2;

    Employee* e = new Employee[n];

    e[0] = Employee("ABC", 30000);
    e[1] = Employee("XYZ", 40000, 5000);

    for(int i = 0; i < n; i++) {
        e[i].display();
    }

    delete[] e;

    return 0;
}