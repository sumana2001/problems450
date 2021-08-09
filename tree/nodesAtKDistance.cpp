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

void printAtLevelK(Node *root, int k){
    if(root==NULL)
        return;
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    printAtLevelK(root->left,k-1);
    printAtLevelK(root->right,k-1);
    return;
}

int printNodesAtK(Node *root, Node *target, int k){
    if(root==NULL){
        return -1;
    }
    if(root==target){
        printAtLevelK(target,k);
        return 0;
    }
    int dl=printNodesAtK(root->left,target,k);
    if(dl!=-1){
        if(dl+1==k){
            cout<<root->data<<" ";
        }
        else{
            printAtLevelK(root->right,k-2-dl);
        }
        return 1+dl;
    }
    int dr=printNodesAtK(root->right,target,k);
    if(dr!=-1){
        if(dr+1==k){
            cout<<root->data<<" ";
        }
        else{
            printAtLevelK(root->left,k-2-dr);
        }
        return 1+dr;
    }
    return -1;
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
    printNodesAtK(root,root->left->left,2);
    return 0;
}