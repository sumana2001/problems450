#include<bits/stdc++.h>
using namespace std;

void solve(int arr[],int n){
    int c0=0,c1=0,c2=0;
    for(int i=0;i<n;i++){
        switch (arr[i])
        {
        case 0:
            c0++;
            break;
        case 1:
            c1++;
            break;
        case 2:
            c2++;
            break;
        }
    }
    int i=0;
    while(c0--){
        arr[i++]=0;
    }
    while(c1--){
        arr[i++]=1;
    }
    while(c2--){
        arr[i++]=2;
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    solve(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;
}