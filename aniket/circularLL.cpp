#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

void display(Node *head){
    Node *ptr=head;
    do{
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }while(ptr!=head);
    cout<<endl;
}

Node *insert(Node *head,int data){
    Node *ptr=new Node();
    Node *p=head;
    ptr->data=data;
    ptr->next=head;
    if(head!=NULL){
        while(p->next!=head)
            p=p->next;
        p->next=ptr;
    }
    else{
        ptr->next=ptr;
    }
    return ptr;
}

int main(){
    Node *head=NULL;
    head=insert(head,10);
    head=insert(head,20);
    display(head);
    head=insert(head,30);
    display(head);
    return 0;
}