#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};

void displayf(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void displayb(Node *ptr)
{
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->prev;
    }
    cout << endl;
}

Node *insert(Node *head, int data)
{
    Node *newnode = new Node();
    Node *ptr = head;
    newnode->data = data;
    newnode->next = ptr;
    if (head != NULL)
    {
        newnode->prev = NULL;
        ptr->prev = newnode;
    }
    else
    {
        newnode->prev = NULL;
        newnode->next = NULL;
    }
    return newnode;
}

int main()
{
    Node *head = NULL;
    head = insert(head, 47);
    head = insert(head, 37);
    head = insert(head, 27);
    head = insert(head, 17);
    displayf(head);
    displayb(head);
    return 0;
}