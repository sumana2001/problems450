#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    //Method 1
    string s1=s;
    reverse(s.begin(),s.end());
    if(s1==s){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    //Method 2
    int n=s.length();
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-i-1]){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}