//3.1
#include<iostream>
using namespace std;

class Employee {
private:
    string name;
    double basicSalary;
    double bonus;

public:

    // Default constructor
    Employee() {
        name = "Unknown";
        basicSalary = 0;
        bonus = 1000;   // default bonus
    }

    // Constructor with default bonus
    Employee(string n, double basic) {
        name = n;
        basicSalary = basic;
        bonus = 1000;
    }

    // Constructor with custom bonus
    Employee(string n, double basic, double b) {
        name = n;
        basicSalary = basic;
        bonus = b;
    }

    inline double calculateTotalSalary() {
        return basicSalary + bonus;
    }

    void display() {
        cout << "\nEmployee Name: " << name;
        cout << "\nBasic Salary: " << basicSalary;
        cout << "\nBonus: " << bonus;
        cout << "\nTotal Salary: " << calculateTotalSalary();
        cout << "\n--------------------------\n";
    }
};

int main() {

    int n = 2;

    Employee* emp = new Employee[n];  // dynamic allocation

    emp[0] = Employee("Ali", 30000);
    emp[1] = Employee("Sara", 40000, 5000);

    for(int i = 0; i < n; i++) {
        emp[i].display();
    }

    delete[] emp;

    return 0;
}