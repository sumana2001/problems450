#include<bits/stdc++.h>
using namespace std;

int main(){
    int count=0,temp=0;
    string s1;
    vector<char> s2;

    for(int i=s1.length();i>=0;i--){
        if(count==4){
            temp=i;
            break;
        }
        if(s1[i]=='.')
            count++;
    }
    for(int i=s1.length();i>=temp;i--){
        s2.push_back(s1[i]);
    }
    for(int i=0;i<s2.size();i++){
        cout<<s2[i];
    }
    return 0;
}