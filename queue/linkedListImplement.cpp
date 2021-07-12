#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Node* front=NULL;
struct Node* rear=NULL;

void enqueue(int data){
    Node* newNode=new Node();
    if(newNode==NULL){
        cout<<"Queue overflow"<<endl;
    }
    else{
        newNode->data=data;
        newNode->next=NULL;
        if(front==NULL){
            front=newNode;
            rear=newNode;
        }
        else{
            rear->next=newNode;
            rear=newNode;
        }
    }
}

int dequeue(){
    if(front==NULL){
        cout<<"Queue is empty"<<endl;
        return 0;
    }
    else{
        Node* ptr=front;
        front=front->next;
        int val=ptr->data;
        free(ptr);
        return val;
    }
}

void display(){
    if(front==NULL){
        cout<<"Queue is empty"<<endl;
    }
    else{
        Node* ptr=front;
        while(ptr!=NULL){
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
        cout<<endl;
    }
}

int main()
{
    enqueue(20);
    enqueue(50);
    enqueue(70);
    enqueue(90);
    display();
    cout<<dequeue()<<endl;
    display();
    cout<<dequeue()<<endl;
    display();
    cout<<dequeue()<<endl;
    display();
    cout<<dequeue()<<endl;
    display();
    return 0;
}