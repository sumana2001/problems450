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

int search(int inorder[], int curr, int start, int end)
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

Node *buildTree(int postorder[], int inorder[], int start, int end)
{
    static int idx = 4;
    if (start > end)
    {
        return NULL;
    }
    int curr = postorder[idx];
    idx--;
    Node *node = new Node(curr);
    if (start == end)
    {
        return node;
    }
    int pos = search(inorder, curr, start, end);
    node->right = buildTree(postorder, inorder, pos + 1, end);
    node->left = buildTree(postorder, inorder, start, pos - 1);
    return node;
}

void inorderPrint(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    inorderPrint(node->left);
    cout << node->data << " ";
    inorderPrint(node->right);
}

int main()
{
    int postorder[] = {4, 2, 5, 3, 1};
    int inorder[] = {4, 2, 1, 5, 3};
    Node *root = buildTree(postorder, inorder, 0, 4);
    inorderPrint(root);
    return 0;
}