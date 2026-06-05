//7.4_25CS027
#include<iostream>
using namespace std;
class shapes
{
    public:

    virtual void area() = 0;
};

class rectangle: public shapes
{
    float lenth,height;

    public:
    rectangle(float l,float h)
    {
        lenth=l;
        height =h;

    }

    void area()
    {
        cout<<"area of rectangle:"<<lenth*height;
    }
};

class circle: public shapes
{
    float radius;

    public:
    circle(float r)
    {
       radius=r;
    }

    void area()
    {
        cout<<"area of circle:"<<3.14*radius*radius;
    }
};


int main()
{
    shapes* arr[2];

    arr[0]= new circle(20);
    arr[1]= new rectangle(20,40);

     for(int i=0;i<2;i++)
     {
        arr[i]->area();
        cout<<endl;


     }

    int n;
    cout<<"enter the no of shapes:";
    cin>>n;
     shapes** s=new shapes*[n];

     for(int i = 0; i < n; i++)
    {
        int choice;
        cout<< "\n1.Rectangle  2.Circle\nEnter choice: ";
        cin>> choice;

        if(choice == 1)
        {
            float l, w;
            cout << "Enter length and width: ";
            cin >> l >> w;
            s[i] = new rectangle(l, w);
        }
        else
        {
            float r;
            cout << "Enter radius: ";
            cin >> r;
            s[i] = new circle(r);
        }
    }

   
    for(int i = 0; i < n; i++)
    {
        s[i]->area();
        cout<<endl;  
    }
    return 0;

}