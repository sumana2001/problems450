#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.length();
    map<char,int> count;
    for(int i=0;i<n;i++){
        count[s[i]]++;
    }
    for(auto i:count){
        if(i.second>1)
            cout<<i.first<<" Count= "<<i.second<<endl;
    }
    return 0;
}