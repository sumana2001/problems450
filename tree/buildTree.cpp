#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *left, *right;
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};

Node *buildTree(){
    int d;
    cin>>d;
    if(d==-1)
        return NULL;
    Node *n=new Node(d);
    n->left=buildTree();
    n->right=buildTree();
    return n;
}

void display(Node *root){
    if(root==NULL)
        return;
    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}

int main(){
    Node *root=buildTree();
    display(root);
    return 0;
}