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

void insert(Node *&head, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        return;
    }
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
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

Node *merge(Node *a, Node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    Node *c;
    if (a->data < b->data){
        c=a;
        c->next=merge(a->next,b);
    }
    else{
        c=b;
        c->next=merge(a,b->next);
    }
    return c;
}

Node *findMid(Node *head){
    Node *slow=head;
    Node *fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

Node *mergeSort(Node *head){
    if(head==NULL || head->next==NULL)
        return head;
    Node *mid=findMid(head);
    Node *a=head;
    Node *b=mid->next;
    mid->next=NULL;
    a=mergeSort(a);
    b=mergeSort(b);
    return merge(a,b);
}

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    insert(head1, 10);
    insert(head1, 7);
    insert(head1, 5);
    insert(head1, 1);
    insert(head2, 6);
    insert(head2, 3);
    insert(head2, 2);
    display(head1);
    display(head2);
    // Node *head=merge(head1,head2);
    // display(head);
    Node *head3=NULL;
    insert(head3,10);
    insert(head3,7);
    insert(head3,5);
    insert(head3,1);
    insert(head3,17);
    insert(head3,2);
    insert(head3,14);
    head3=mergeSort(head3);
    display(head3);
    return 0;
}