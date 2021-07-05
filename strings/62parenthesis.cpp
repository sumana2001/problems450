#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<char> st;
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='{' || s[i]=='(' || s[i]=='[')
            st.push(s[i]);
        else if(s[i]=='}'){
            if(st.top()=='{')
                st.pop();
            else{
                cout<<"No";
                return 0;
            }
        }
        else if(s[i]==']'){
            if(st.top()=='[')
                st.pop();
            else{
                cout<<"No";
                return 0;
            }
        }
        else if(s[i]==')'){
            if(st.top()=='(')
                st.pop();
            else{
                cout<<"No";
                return 0;
            }
        }
    }
    if(st.empty()){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}

