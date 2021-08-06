#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left,*right;
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};

int height(Node *root){
    if(root==NULL)
        return 0;
    return max(height(root->left),height(root->right))+1;
}

bool isBalanced(Node *root){
    if(root==NULL){
        return true;
    }
    if(isBalanced(root->left)==false){
        return false;
    }
    if(isBalanced(root->right)==false){
        return false;
    }
    int lHeight=height(root->left);
    int rHeight=height(root->right);
    if(abs(lHeight-rHeight)<=1){
        return true;
    }
    else{
        return false;
    }
}

bool isBalanced2(Node *root, int *height){
    if(root==NULL){
        *height=0;
        return true;
    }
    int lh=0,rh=0;
    if(isBalanced2(root->left,&lh)==false){
        return false;
    }
    if(isBalanced2(root->right,&rh)==false){
        return false;
    }
    *height=max(lh,rh)+1;
    if(abs(lh-rh)<=1){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->left->left = new Node(5);
    if(isBalanced(root)){
        cout<<"Balanced"<<endl;
    }
    else{
        cout<<"Unbalanced"<<endl;
    }
    if(isBalanced(root2)){
        cout<<"Balanced"<<endl;
    }
    else{
        cout<<"Unbalanced"<<endl;
    }
    int height=0;
    if(isBalanced2(root,&height)){
        cout<<"Balanced"<<endl;
    }
    else{
        cout<<"Unbalanced"<<endl;
    }
    int height2=0;
    if(isBalanced2(root2,&height2)){
        cout<<"Balanced"<<endl;
    }
    else{
        cout<<"Unbalanced"<<endl;
    }
    return 0;
}