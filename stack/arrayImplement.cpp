#include <bits/stdc++.h>
using namespace std;
#define MAX 5

class Stack
{
public:
    int top;
    int a[MAX];
    Stack() { top = -1; }
    bool isEmpty();
    bool push(int x);
    int peek();
    int pop();
};

bool Stack::isEmpty()
{
    if (top < 0)
    {
        return true;
    }
    return false;
}

bool Stack::push(int x){
    if(top==MAX-1){
        cout<<"Stack overflow."<<endl;
        return false;
    }
    else{
        a[++top]=x;
        cout<<x<<" pushed to stack."<<endl;
        return true;
    }
}

int Stack::peek(){
    if(top<0){
        cout<<"Stack is empty."<<endl;
        return 0;
    }
    else{
        cout<<a[top]<<" peek"<<endl;
        return a[top];
    }
}

int Stack::pop(){
    if(top<0){
        cout<<"Stack underflow."<<endl;
        return 0;
    }
    else{
        int x=a[top];
        top--;
        cout<<x<<" popped out of the stack."<<endl;
        return x;
    }
}

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    while(!s.isEmpty()){
        s.peek();
        s.pop();
    }
    return 0;
}