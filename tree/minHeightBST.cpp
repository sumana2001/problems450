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

Node *sortedArrayToBST(int arr[], int start, int end){
    if(start>end)
        return NULL;
    int mid=(start+end)/2;
    Node *root=new Node(arr[mid]);
    root->left=sortedArrayToBST(arr,start,mid-1);
    root->right=sortedArrayToBST(arr,mid+1,end);
    return root;
}

void preorder(Node *root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    int arr[]={1,2,3,4,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    Node *root=sortedArrayToBST(arr,0,n-1);
    preorder(root);
    return 0;
}