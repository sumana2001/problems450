#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void insertAtHead(Node *&head, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        return;
    }
    Node *ptr = new Node(data);
    ptr->next = head;
    head = ptr;
}

void insertAtMiddle(Node *&head, int data, int pos)
{
    if (pos == 0)
    {
        insertAtHead(head, data);
        return;
    }
    Node *ptr = head;
    while (pos - 1)
    {
        ptr = ptr->next;
        pos--;
    }
    Node *newNode = new Node(data);
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *recReverse(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *ptr = recReverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return ptr;
}

void iterReverse(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}

Node *kReverse(Node* &head,int k){
    if(head==NULL)
        return NULL;
    Node *prev=NULL;
    Node *curr=head;
    Node *next;
    int count=1;
    while(curr!=NULL && count<=k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL){
        head->next=kReverse(next,k);
    }
    return prev;
}

int main()
{
    Node *head = NULL;
    insertAtHead(head, 5);
    insertAtHead(head, 6);
    insertAtHead(head, 7);
    insertAtHead(head, 8);
    display(head);
    // insertAtMiddle(head, 10, 4);
    // display(head);
    // head = recReverse(head);
    // display(head);
    // iterReverse(head);
    // display(head);
    head=kReverse(head,3);
    display(head);
    return 0;
}