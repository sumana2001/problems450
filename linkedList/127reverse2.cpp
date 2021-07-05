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

Node *reverse(Node *head, int k)
{
    Node *curr = head;
    Node *next = NULL;
    Node *prev = NULL;
    int counter = k;
    while (counter-- && curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    if (head != NULL)
    {
        head->next = reverse(next, k);
    }
    return prev;
}

int main()
{
    Node *head = NULL;
    head = insert(head, 80);
    head = insert(head, 70);
    head = insert(head, 60);
    head = insert(head, 50);
    head = insert(head, 40);
    head = insert(head, 30);
    head = insert(head, 20);
    head = insert(head, 10);
    display(head);
    int k = 3;
    head = reverse(head, k);
    display(head);
    return 0;
}