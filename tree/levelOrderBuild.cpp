#include<bits/stdc++.h>
using namespace std;

class Node{
public: 
    int data;
    Node *left, *right;
    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

Node *build(){
    int d;
    cin>>d;
    queue<Node *> q;
    Node *root=new Node(d);
    q.push(root);
    while(!q.empty()){
        Node *n=q.front();
        q.pop();
        int c1,c2;
        cin>>c1>>c2;
        if(c1!=-1){
            n->left=new Node(c1);
            q.push(n->left);
        }
        if(c2!=-1){
            n->right=new Node(c2);
            q.push(n->right);
        }
    }
    return root;
}

void inorder(Node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node *root=build();
    inorder(root);
    return 0;
}