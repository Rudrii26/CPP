//7.5_25CS027
#include<iostream>
using namespace std;


class Grading
{
protected:
    int marks;

public:
    void getMarks()
    {
        cout << "Enter marks: ";
        cin >> marks;
    }

    virtual void calculateGrade() = 0; // pure virtual
};


class UG : public Grading
{
public:
    void calculateGrade()
    {
        if(marks >= 75)
            cout << "UG Grade: A\n";
        else if(marks >= 60)
            cout << "UG Grade: B\n";
        else if(marks >= 50)
            cout << "UG Grade: C\n";
        else
            cout << "UG Grade: Fail\n";
    }
};

class PG : public Grading
{
public:
    void calculateGrade()
    {
        if(marks >= 80)
            cout << "PG Grade: A\n";
        else if(marks >= 65)
            cout << "PG Grade: B\n";
        else if(marks >= 55)
            cout << "PG Grade: C\n";
        else
            cout << "PG Grade: Fail\n";
    }
};

int main()
{
    Grading* g;
    int choice;

    cout << "1. Undergraduate\n2. Postgraduate\nEnter choice: ";
    cin >> choice;

    if(choice == 1)
        g = new UG();
    else
        g = new PG();

    g->getMarks();
    g->calculateGrade(); 

    return 0;
}