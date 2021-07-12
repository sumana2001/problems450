#include <bits/stdc++.h>
using namespace std;
#define MAX 5

class Queue
{
public:
    int front, rear;
    int a[MAX];
    Queue() { int front = rear = 0; }
    void enqueue(int data);
    void dequeue();
    void display();
    void peek();
};

void Queue::enqueue(int data){
    if(rear==MAX){
        cout<<"Queue overflow"<<endl;
        return;
    }
    a[rear++]=data;
}

void Queue::dequeue(){
    if(front==rear){
        cout<<"Queue underflow"<<endl;
        return;
    }
    for(int i=0;i<rear-1;i++){
        a[i]=a[i+1];
    }
    rear--;
}

void Queue::display(){
    if(front==rear){
        cout<<"Stack is empty"<<endl;
        return;
    }
    for(int i=front;i<rear;i++){
        cout<<a[i]<<" <- ";
    }
    cout<<endl;
}

void Queue::peek(){
    if(front==rear){
        cout<<"Stack is empty"<<endl;
        return;
    }
    cout<<a[front]<<" is at front of queue"<<endl;
}

int main()
{
    Queue q;
    q.enqueue(10);
    q.display();
    q.enqueue(20);
    q.display();
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.peek();
    q.dequeue();
    q.display();
    return 0;
}