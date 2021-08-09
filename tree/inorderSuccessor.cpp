#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        return new Node(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

Node *successor(Node *root, Node *target)
{
    if (target->right != NULL)
    {
        Node *temp = root->right;
        while (temp != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }
    Node *temp = root;
    Node *succ = NULL;
    while (temp != NULL)
    {
        if (temp->data > target->data)
        {
            succ = temp;
            temp = temp->left;
        }
        else if (temp->data < target->data)
        {
            temp = temp->right;
        }
        else
        {
            break;
        }
    }
    return succ;
}

int main()
{
    Node *root = NULL;
    int arr[] = {3, 2, 5, 1, 8, 4};
    for (int a : arr)
    {
        root = insert(root, a);
    }
    Node *temp = root->left->left;
    Node *res = successor(root, temp);
    cout << res->data << " ";
    return 0;
}