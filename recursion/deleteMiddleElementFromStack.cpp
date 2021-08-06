#include<bits/stdc++.h>
using namespace std;

void deleteMiddle(stack<int> &s, int mid){
    if(mid==1){
        s.pop();
        return;
    }
    int temp=s.top();
    s.pop();
    deleteMiddle(s,mid-1);
    s.push(temp);
}

int main(){
    stack<int> s;
    for(int i=0;i<5;i++){
        int num;
        cin>>num;
        s.push(num);
    }
    int n=s.size();
    deleteMiddle(s,(n/2)+1);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}