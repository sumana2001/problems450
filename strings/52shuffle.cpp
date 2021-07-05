#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    int n=s1.length();
    int m=s2.length();
    int o=s3.length();
    if(n+m!=o){
        cout<<"NO";
        return 0;
    }
    string temp=s1+s2;
    sort(temp.begin(),temp.end());
    sort(s3.begin(),s3.end());
    for(int i=0;i<o;i++){
        if(temp[i]!=s3[i]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}