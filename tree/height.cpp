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

int height(struct Node *node)
{
    if (node == NULL)
        return 0;
    int lheight = height(node->left);
    int rheight = height(node->right);
    return max(lheight, rheight) + 1;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << height(root);
    return 0;
}