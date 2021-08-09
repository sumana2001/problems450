#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *left,*right;
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};

void display(Node *root){
    if(root==NULL){
        return;
    }
    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}

class Pair{
public:
    int inc;
    int exc;
};

Pair maxSubsetSum(Node *root){
    Pair p;
    if(root==NULL){
        p.inc=p.exc=0;
        return p;
    }
    Pair Left=maxSubsetSum(root->left);
    Pair Right=maxSubsetSum(root->right);
    p.inc=Left.exc+Right.exc+root->data;
    p.exc=max(Left.exc,Left.inc)+max(Right.exc,Right.inc);
    return p;
}

int main(){
    Node *root=new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->left = new Node(7);
    display(root);
    Pair p=maxSubsetSum(root);
    cout<<"\n"<<max(p.inc,p.exc);
    return 0;
}