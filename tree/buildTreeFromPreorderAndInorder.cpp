#include <bits/stdc++.h>
using namespace std;

int idx = 0;

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

int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

Node *buildTree(int preorder[], int inorder[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int curr = preorder[idx];
    idx++;
    Node *node = new Node(curr);
    if (start == end)
    {
        return node;
    }
    int pos = search(inorder, start, end, curr);
    node->left = buildTree(preorder, inorder, start, pos - 1);
    node->right = buildTree(preorder, inorder, pos + 1, end);
    return node;
}

void inorderPrint(Node *node)
{
    if (node == NULL)
        return;
    inorderPrint(node->left);
    cout << node->data << " ";
    inorderPrint(node->right);
}

int main()
{
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};
    Node *root = buildTree(preorder, inorder, 0, 4);
    inorderPrint(root);
    return 0;
}