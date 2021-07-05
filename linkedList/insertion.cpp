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

Node *insertAtFront(Node *head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

Node *insertInBetween(Node *head, int data, int index)
{
    Node *newNode = new Node();
    Node *p = head;
    newNode->data = data;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    newNode->next = p->next;
    p->next = newNode;
    return head;
}

Node *insertAtEnd(Node *head, int data)
{
    Node *newNode = new Node();
    Node *p = head;
    newNode->data = data;
    while (p->next != NULL)
    {
        p = p->next;
    }
    newNode->next = NULL;
    p->next = newNode;
    return head;
}

Node *insertAfterNode(Node *head, Node *ptr, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = ptr->next;
    ptr->next = newNode;
    return head;
}

int main()
{
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 50;
    third->next = NULL;

    display(head);
    head = insertAtFront(head, 15);
    display(head);
    head = insertInBetween(head, 35, 2);
    display(head);
    head = insertAtEnd(head, 75);
    display(head);
    head = insertAfterNode(head, second, 95);
    display(head);
    return 0;
}