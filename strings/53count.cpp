#include<bits/stdc++.h>
using namespace std;

string count(int n){
    string str="1";
    if(n==1){
        return str;
    }for(int i=2;i<=n;i++){
        string result="";
        int count=1;
        int j=0;
        while(j<str.length()){
            if(str[j]==str[j+1]){
                count++;
            }
            else{
                result.push_back(char('0'+count));
                result.push_back(str[j]);
                count=1;
            }
            j++;
        }
        str=result;
    }
    
    return str;
}

int main(){
    int n;
    cin>>n;
    cout<<count(n);
    return 0;
}