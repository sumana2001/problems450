#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void display(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

bool detectLoop(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast)
            return true;
    }
    return false;
}

int main()
{
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
    cout<<detectLoop(head);
    return 0;
}