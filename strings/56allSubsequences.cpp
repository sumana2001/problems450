#include<bits/stdc++.h>
using namespace std;

void solve(string s,string result){
    if(s.empty()){
        cout<<result<<endl;
        return;
    }
    solve(s.substr(1),result+s[0]);
    solve(s.substr(1),result);
}

int main(){
    string s,result="";
    cin>>s;
    solve(s,result);
    return 0;
}