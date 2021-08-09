#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void traversal(Node *root, int d, map<int, vector<int> > &m){
    if(root==NULL)
        return;
    m[d].push_back(root->data);
    traversal(root->left,d-1,m);
    traversal(root->right,d+1,m);
}

void verticalPrint(Node *root){
    map<int,vector<int> > m;
    int d=0;
    traversal(root,d,m);
    for(auto p:m){
        int key=p.first;
        vector<int> line=p.second;
        for(auto data:line){
            cout<<data<<" ";
        }
        cout<<endl;
    }
}

int main(){
    Node *root=new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    verticalPrint(root);
    return 0;
}