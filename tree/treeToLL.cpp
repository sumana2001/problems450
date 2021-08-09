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

class LinkedList{
public:
    Node *head;
    Node *tail;
};

LinkedList treeToLL(Node *root){
    LinkedList l;
    if(root==NULL){
        l.head=l.tail=NULL;
        return l;
    }
    if(root->left==NULL && root->right==NULL){
        l.head=l.tail=root;
    }
    else if(root->left!=NULL && root->right==NULL){
        LinkedList lt=treeToLL(root->left);
        lt.tail->right=root;
        l.head=lt.head;
        l.tail=root;
    }
    else if(root->left==NULL && root->right!=NULL){
        LinkedList rt=treeToLL(root->right);
        root->right=rt.head;
        l.head=root;
        l.tail=rt.tail;
    }
    else{
        LinkedList lt=treeToLL(root->left);
        LinkedList rt=treeToLL(root->right);
        lt.tail->right=root;
        root->right=rt.head;
        l.head=lt.head;
        l.tail=rt.tail;
    }
    return l;
}

int main(){
    Node *root=NULL;
    int arr[]={3,2,5,1,8,4};
    for(int a:arr){
        root=insert(root,a);
    }
    LinkedList l=treeToLL(root);
    Node *temp=l.head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->right;
    }
    return 0;
}