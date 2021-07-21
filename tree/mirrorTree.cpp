#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void inorder(struct Node *node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void mirror1(struct Node *node)
{
    if (node == NULL)
        return;
    mirror1(node->left);
    mirror1(node->right);
    struct Node *temp;
    temp = node->left;
    node->left = node->right;
    node->right = temp;
}

void mirror2(struct Node *node)
{
    if (node == NULL)
        return;
    queue<Node *> q;
    q.push(node);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        swap(curr->left, curr->right);
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    inorder(root);
    cout << endl;
    mirror2(root);
    inorder(root);
    cout << endl;
    mirror2(root);
    inorder(root);
    return 0;
}