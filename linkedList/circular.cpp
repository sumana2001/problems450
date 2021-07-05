#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void display(Node *head)
{
    Node *ptr = head;
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);
    cout << endl;
}

Node *insert(Node *head, int data)
{
    Node *newnode = new Node();
    Node *ptr = head;
    newnode->data = data;
    newnode->next = head;
    if (head != NULL)
    {
        while (ptr->next != head)
            ptr = ptr->next;
        ptr->next = newnode;
    }
    else
        newnode->next = newnode;
    return newnode;
}

Node *deletion(Node *head)
{
    Node *ptr = head;
    Node *p = head;
    if (head != NULL)
    {
        while (ptr->next != head)
            ptr = ptr->next;
        ptr->next = p->next;
        head = ptr->next;
        free(p);
    }
    else
        cout << "List is empty";
    return head;
}

int main()
{
    Node *head = NULL;
    head = insert(head, 46);
    head = insert(head, 26);
    head = insert(head, 16);
    display(head);
    head = deletion(head);
    display(head);
    return 0;
}
