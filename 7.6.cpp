//7.6_25CS027
#include<iostream>
using namespace std;

class Base
{
public:
    virtual ~Base()
    {
        cout << "Base Destructor Called\n";
    }
};

class Derived : public Base
{
    int* data;

public:
    Derived()
    {
        data = new int[5];
        cout << "Memory Allocated in Derived\n";
    }

    ~Derived()
    {
        delete[] data;
        cout << "Derived Destructor Called (Memory Freed)\n";
    }
};

int main()
{
    Base* b = new Derived();  
    delete b;        
    return 0;
}