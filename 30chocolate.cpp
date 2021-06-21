#include<bits/stdc++.h>
using namespace std;

int chocolateDiff(int arr[],int n, int m){
    if(m==0||n==0)
        return 0;
    if(n<m)
        return -1;
    sort(arr,arr+n);
    int minVal=INT_MAX;
    for(int i=0;i+m-1<n;i++){
        int curr=arr[i+m-1]-arr[i];
        minVal=min(curr,minVal);
    }
    return minVal;
}

int main(){
    int arr[] = {12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m=7;
    cout<<chocolateDiff(arr,n,m);
    return 0;
}