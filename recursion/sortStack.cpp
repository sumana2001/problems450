#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, int temp){
    if(s.empty() || s.top()>temp){
        s.push(temp);
        return;
    }
    int val=s.top();
    s.pop();
    insert(s,temp);
    s.push(val);
}

void sort(stack<int> &s){
    if(s.empty())
        return;
    int temp=s.top();
    s.pop();
    sort(s);
    insert(s,temp);
}

int main(){
    stack<int> s;
    for(int i=0;i<7;i++){
        int num;
        cin>>num;
        s.push(num);
    }
    sort(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}