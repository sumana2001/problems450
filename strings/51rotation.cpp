#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1,s2;
    cin>>s1>>s2;
    if(s1.length()!=s2.length()){
        cout<<"NO";
        return 0;
    }
    string temp=s1+s1;
    if(temp.find(s2)!=string::npos){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}