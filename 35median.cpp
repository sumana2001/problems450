#include<bits/stdc++.h>
using namespace std;

int median(int arr[],int n){
    sort(arr,arr+n);
    if(n%2!=0)
        return arr[((n+1)/2)-1];
    else
        return (arr[(n/2)-1]+arr[((n+1)/2)])/2;
}

int main(){
    int arr[] = {56,67,30,79};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<median(arr,n);
    return 0;
}