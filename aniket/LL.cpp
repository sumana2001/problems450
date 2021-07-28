#include <bits/stdc++.h>
using namespace std;

//insert at front, rear, at a given index,after a given value
//deletion at front, rear, at a given index,after a given value
//circular linked list insertion at front

class Node
{
public:
    int data;
    Node *next;
};

void display(Node *ptr){
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

Node *insertAtFront(Node *head,int data){
    Node *ptr=new Node();
    ptr->data=data;
    ptr->next=head;
    return ptr;
}

Node *insertAtEnd(Node *head,int data){
    Node *ptr=new Node();
    Node *p=head;
    ptr->data=data;
    while(p->next!=NULL){
        p=p->next;
    }
    ptr->next=NULL;
    p->next=ptr;
    return head;
}

Node *insertAtIndex(Node *head,int index, int data){
    Node *ptr=new Node();
    Node *p=head;
    ptr->data=data;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

Node *insertAfterValue(Node *head, int value, int data){
    Node *ptr=new Node();
    Node *p=head;
    ptr->data=data;
    while(p->data!=value){
        p=p->next;
    }
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

Node *deleteAtFirst(Node *head){
    Node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

Node *deleteAtEnd(Node *head){
    Node *ptr=head;
    Node *temp=ptr->next;
    while(temp->next!=NULL){
        ptr=ptr->next;
        temp=temp->next;
    }
    ptr->next=NULL;
    free(temp);
    return head;
}

Node *deleteAtIndex(Node *head, int index){
    Node *ptr=head;
    Node *temp=ptr->next;
    int i=0;
    while(i!=index-1){
        ptr=ptr->next;
        temp=temp->next;
        i++;
    }
    ptr->next=temp->next;
    free(temp);
    return(head);
}

Node *deleteAfterValue(Node *head, int value){
    Node *ptr=head;
    Node *temp=ptr->next;
    while(ptr->data!=value){
        ptr=ptr->next;
        temp=temp->next;
    }
    ptr->next=temp->next;
    free(temp);
    return head;
}

int main()
{
    Node *head=new Node();
    head->data=10;
    head->next=NULL;
    display(head);
    head=insertAtFront(head,20);
    display(head);
    head=insertAtEnd(head,50);
    display(head);
    head=insertAtIndex(head,2,70);
    display(head);
    head=insertAfterValue(head,20,100);
    display(head);
    head=deleteAtFirst(head);
    display(head);
    head=deleteAtEnd(head);
    display(head);
    head=deleteAtIndex(head,1);
    display(head);
    head=deleteAfterValue(head,100);
    display(head);
    return 0;
}
