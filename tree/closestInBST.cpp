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
        return new Node(data);
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

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int closest(Node *root, int target)
{
    int closest=-1;
    int diff = INT_MAX;
    Node *temp = root;
    while (temp != NULL)
    {
        int curr_diff = abs(temp->data - target);
        if (curr_diff == 0)
            return temp->data;
        if (curr_diff < diff)
        {
            diff = curr_diff;
            closest = temp->data;
        }
        if (temp->data < target)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    return closest;
}

int main()
{
    Node *root = NULL;
    int arr[] = {4, 2, 6, 23, 5, 1, 10};
    for (int a : arr)
    {
        root = insert(root, a);
    }
    // inorder(root);
    cout << closest(root, 10)<<endl;
    return 0;
}