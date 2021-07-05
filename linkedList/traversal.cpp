#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

void display(Node* ptr){
    while(ptr!=NULL){
        cout<<"Element: "<<ptr->data<<endl;
        ptr=ptr->next;
    }
}

int main(){
    Node* head=NULL;
    Node* second=NULL;
    Node* third=NULL;

    head=new Node();
    second=new Node();
    third=new Node();

    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=50;
    third->next=NULL;

    display(head);
    return 0;
}