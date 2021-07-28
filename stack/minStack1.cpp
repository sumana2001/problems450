//Minimum Element in Stack with Extra space
#include<bits/stdc++.h>
using namespace std;

stack<int> s;
stack<int> ss;

void push(int a){
    s.push(a);
    if(ss.size()==0 || ss.top()>=a){
        ss.push(a);
    }
}

void pop(){
    if(s.size()==0)
        return;
    int ans=s.top();
    s.pop();
    if(ss.top()==ans)
        ss.pop();
}

int getMin(){
    if(ss.size()==0)
        return -1;
    return ss.top();
}

int main(){
    push(18);
    cout<<getMin()<<endl;
    push(10);
    cout<<getMin()<<endl;
    pop();
    cout<<getMin()<<endl;
    return 0;
}