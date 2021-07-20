#include<bits/stdc++.h>
using namespace std;

int add(int x,int y){
    if(y==0)
        return x;
    return add(x^y,(x&y)<<1);
}

int main(){
    int x=10,y=40;
    cout<<add(x,y);
    return 0;
}