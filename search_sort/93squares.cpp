#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=9,count=0;
    for(int i=1;i*i<n;i++){
        count++;
    }
    cout<<count;
    return 0;
}