#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
        int data;
        Node* next;
};

struct Node* top;

void push(int data){
    struct Node* temp=new Node();
    if(!temp){
        cout<<"Stack overflow."<<endl;
        return;
    }
    temp->data=data;
    temp->next=top;
    top=temp;
}

void pop(){
    if(top==NULL){
        cout<<"Stack underflow."<<endl;
        return;
    }
    struct Node* temp=top;
    top=top->next;
    temp->next=NULL;
    free(temp);
}

bool isEmpty(){
    if(top==NULL){
        return true;
    }
    return false;
}

int peek(){
    if(isEmpty()){
        return 0;
    }
    else{
        return top->data;
    }
}

void display(){
    if(top==NULL){
        cout<<"Stack is empty"<<endl;
        return;
    }
    struct Node* ptr=top;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

int main(){
    push(11);
    push(22);
    push(33);
    push(44);
    display();
    cout << "Top element is "<< peek() << endl;
    pop();
    pop();
    display();
    cout << "Top element is "<< peek() << endl;
    return 0;
}