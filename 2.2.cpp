//2.2
#include<iostream>
using namespace std;

class student {
    int stdID;
    string stdName;
    int marks[3];

public:

    student() {
        stdID = 0;
        stdName = "None";
        for(int i = 0; i < 3; i++) {
            marks[i] = 0;
        }
    }

    student(int id, string name, int m[3]) {
        stdID = id;
        stdName = name;

        for(int i = 0; i < 3; i++) {
            if(m[i] >= 0 && m[i] <= 100)
                marks[i] = m[i];
            else
                marks[i] = 0;   
        }
    }

    float avg() {
        return (marks[0] + marks[1] + marks[2]) / 3.0;
    }

    void display() {
        cout << "\nID: " << stdID;
        cout << "\nName: " << stdName;
        cout << "\nMarks: ";
        for(int i = 0; i < 3; i++)
            cout << marks[i] << " ";
        cout << "\nAverage: " << avg() << endl;
    }
};

int main() {

    int m1[3] = {85, 90, 88};
    int m2[3] = {70, 75, 72};

    student s1;                      
    student s2(1, "Ali", m1);        
    student s3(2, "Sara", m2);

    s1.display();
    s2.display();
    s3.display();

    return 0;
}