#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

void display(Node* ptr){
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

Node* insert(Node* head,int data){
    Node* newNode=new Node();
    newNode->data=data;
    newNode->next=head;
    return newNode;
}

Node* deleteAtFirst(Node* head){
    Node* p=head;
    head=head->next;
    free(p);
    return head;
}

Node* deleteAtIndex(Node* head,int index){
    Node* p=head;
    Node* q=p->next;
    int i=0;
    while(i!=index-1){
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    free(q);
    return head;
}

Node* deleteAtEnd(Node* head){
    Node* p=head;
    Node* q=p->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

Node* deleteAtValue(Node* head,int data){
    Node* p=head;
    Node* q=p->next;
    while(q->data!=data){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}

int main(){
    Node* head=NULL;
    head=insert(head,10);
    head=insert(head,20);
    head=insert(head,30);
    head=insert(head,40);
    display(head);
    head=deleteAtFirst(head);
    display(head);
    head=deleteAtIndex(head,1);
    display(head);
    head=deleteAtEnd(head);
    display(head);
    head=deleteAtValue(head,30);
    display(head);
    return 0;
}