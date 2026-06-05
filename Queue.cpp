#include<iostream>
using namespace std;

class queue{
    private:
    int front;
    int rear;
    int size=4;
    int q[];

    public:
    queue(){
        front = -1;
        rear = -1;
    }

    void push(int x){
        if(rear + 1 == size){
            cout<<"The Queue is full!"<<endl;
        }
        else{
            if(rear == -1){
                front = 0;
            }
            q[++rear] = x;
        }
    }
    int pop(){
        if(rear == front == -1){
            cout<<"The queue is already empty."<<endl;
        }
        else{
            int temp = q[front];
            if(front == rear){
                front = rear = -1;
            }
            front++;
            return temp;
        }
    }
};
int main(){
    queue q;
    q.push(1);
    return 0;
}