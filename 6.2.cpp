//6.2_25CS027
#include<iostream>
using namespace std;

class Person{
    protected:
    string name;
    int age;

    public:
    Person(string nm, int a){
        name = nm;
        age = a;
    }
};
class Employee: public Person{
    protected:
    int ID;
    
    public:
    Employee(string nm, int a, int id): Person(nm, a){
        ID = id;
    }
};
class Manager: public Employee{
    protected:
    string department;

    public:
    Manager(string nm, int a, int id, string dept): Employee(nm, a, id){
        department = dept;
    }
    void display(){
        cout<<"Name:" <<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"ID: "<<ID<<endl;
        cout<<"Department: "<<department<<endl;
    }
};
int main(){
    Manager m("ABC", 18, 27, "CSE");
    m.display();
    return 0;
}