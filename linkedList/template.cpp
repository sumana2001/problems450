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

int main()
{
    Node *head = NULL;
    head = insert(head, 40);
    head = insert(head, 30);
    head = insert(head, 20);
    head = insert(head, 10);
    display(head);
    return 0;
}