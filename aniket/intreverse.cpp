#include<bits/stdc++.h>
using namespace std;

int main(){
    int num=0;
    if(num==0){
        cout<<0;
        return 0;
    }
    if(num<0){
        cout<<"-";
    }
    int n=abs(num);
    int count=0;
    while(n){
        int x=n%10;
        if(count==0 && x==0){
            count++;
        }
        else{
            cout<<x;
            count++;
        }
        n=n/10;
    }
    return 0;
}