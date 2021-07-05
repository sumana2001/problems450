#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int zeroCount=0,oneCount=0,count=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0'){
            zeroCount++;
        }
        else{
            oneCount++;
        }
        if(zeroCount==oneCount){
            count++;
            zeroCount=0;
            oneCount=0;
        }
    }
    if(count==0){
        cout<<-1<<endl;
    }
    else{
        cout<<count<<endl;
    }
    return 0;
}