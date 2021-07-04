#include<bits/stdc++.h>
using namespace std;

void reverse(vector<char> v){
    int n=v.size();
    for(int i=0;i<n/2;i++){
        char temp=v[i];
        v[i]=v[n-i-1];
        v[n-i-1]=temp;
    }
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
}

int main(){
    vector<char> v;
    v.push_back('a');
    v.push_back('b');
    v.push_back('c');
    reverse(v);
    return 0;
}