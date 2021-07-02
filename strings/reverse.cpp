#include<bits/stdc++.h>
using namespace std;

void reverse(vector<string> v){
    int n=v.size();
    for(int i=0;i<n/2;i++){
        string temp=v[i];
        v[i]=v[n-i];
        v[n-i]=temp;
    }
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
}

int main(){
    vector<string> v;
    char test[] = "abcde";
    v.push_back(test);
    reverse(v);
    return 0;
}