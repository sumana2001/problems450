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

Node *insert(Node *root,int data){
    if(root==NULL){
        return new Node(data);
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}

void inorder(Node *root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node *root=NULL;
    int arr[]={8,10,2,4,24,1,3};
    for(int a:arr){
        root=insert(root,a);
    }
    inorder(root);
    return 0;
}