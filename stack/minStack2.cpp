//Minimum Element in Stack with Extra space
#include<bits/stdc++.h>
using namespace std;

stack<int> s;
int minEle;

void push(int x){
    if(s.size()==0){
        s.push(x);
        minEle=x;
    }
    else if(x>=minEle){
        s.push(x);
    }
    else if(x<minEle){
        s.push(2*x-minEle);
        minEle=x;
    }
}

void pop(){
    if(s.size()==0)
        return;
    else if(s.top()>=minEle){
        s.pop();
    }
    else if(s.top()<minEle){
        minEle=2*minEle-s.top();
        s.pop();
    }
}

int top(){
    if(s.size()==0)
        return -1;
    else if(s.top()>=minEle){
        return s.top();
    }
    else if(s.top()<minEle){
        return minEle;
    }
    return 0;
}

int getMin(){
    if(s.size()==0)
        return -1;
    else
        return minEle;
}

int main(){
    push(5);
    cout<<getMin()<<endl;
    push(3);
    cout<<getMin()<<endl;
    push(7);
    cout<<getMin()<<endl;
    cout<<top()<<endl;
    push(2);
    cout<<getMin()<<endl;
    pop();
    cout<<getMin()<<endl;
    return 0;
}