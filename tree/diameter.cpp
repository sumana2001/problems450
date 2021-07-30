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

int findHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(findHeight(root->left), findHeight(root->right)) + 1;
}

int findDiameter(Node *root)
{
    if (root == NULL)
        return 0;
    int lHeight = findHeight(root->left);
    int rHeight = findHeight(root->right);
    int currDiameter = lHeight + rHeight + 1;
    return max(currDiameter, max(findDiameter(root->left), findDiameter(root->right)));
}

int findDiameter2(Node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int lDiameter = findDiameter2(root->left, &lh);
    int rDiameter = findDiameter2(root->right, &rh);
    int currDiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;
    return max(currDiameter, max(lDiameter, rDiameter));
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout << findDiameter(root) << endl;
    int height = 0;
    cout << findDiameter2(root, &height) << endl;
    return 0;
}