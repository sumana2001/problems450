#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};

void postorder(struct Node *node){
    stack<Node*> s1,s2;
    s1.push(node);
    while(!s1.empty()){
        struct Node* curr=s1.top();
        s1.pop();
        s2.push(curr);
        if(curr->left)
            s1.push(curr->left);
        if(curr->right)
            s1.push(curr->right);
    }
    while(!s2.empty()){
        struct Node* temp=s2.top();
        cout<<temp->data<<" ";
        s2.pop();
    }
}

int main(){
    struct Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    postorder(root);
    return 0;
}