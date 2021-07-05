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

Node *insert(Node *head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    if (head != NULL)
    {
        newNode->next = head;
    }
    else
    {
        newNode->next = NULL;
    }
    return newNode;
}

Node* reversei(Node *head)
{
    Node *prev = NULL;
    Node *next = NULL;
    Node *current = head;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node* reverser(Node *head)
{
    if(head==NULL || head->next==NULL)
        return head;
    Node* rest=reverser(head->next);
    head->next->next=head;
    head->next=NULL;
    return rest;
}

int main()
{
    Node *head = NULL;
    head = insert(head, 40);
    head = insert(head, 30);
    head = insert(head, 20);
    head = insert(head, 10);
    display(head);
    head=reversei(head);
    display(head);
    return 0;
}