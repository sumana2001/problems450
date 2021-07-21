#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void push(Node **head_ref, int newdata)
{
    Node *newNode = new Node();
    newNode->data = newdata;
    newNode->next = (*head_ref);
    (*head_ref) = newNode;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteNode(Node *node)
{
    Node *prev;
    if (node == NULL)
        return;
    else
    {
        while (node->next != NULL)
        {
            node->data = node->next->data;
            prev = node;
            node = node->next;
        }
        prev->next = NULL;
    }
}

void deleteNode2(Node *node)
{
    struct Node *temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    free(temp);
}

int main()
{
    Node *head = NULL;
    push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1);
    printList(head);
    deleteNode(head);
    deleteNode2(head);
    printList(head);
    return 0;
}