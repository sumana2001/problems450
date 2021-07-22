#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

struct node *insert(struct node *node, int data)
{
    if (node == NULL)
    {
        node = new struct node(data);
        return node;
    }
    else
    {
        if (data <= node->data)
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);
        return node;
    }
}

int minValue(struct node *node)
{
    struct node *curr = node;
    while (curr->left != NULL)
        curr = curr->left;
    return curr->data;
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 1);
    insert(root, 3);
    insert(root, 6);
    insert(root, 5);
    cout << minValue(root);
    return 0;
}