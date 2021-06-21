#include<bits/stdc++.h>
using namespace std;

int swaps(int arr[],int n,int k){
    int good=0,bad=0;
    int minswap=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<=k)
            good++;
    }
    for(int i=0;i<good;i++){
        if(arr[i]>k)
            bad++;
    }
    int i=0,j=good-1;
    while(j<n){
        minswap=min(minswap,bad);
        j++;
        if(arr[j]>k)
            bad++;
        if(arr[i]>k){
            bad--;
            i++;
        }
    }
    if(minswap==INT_MAX)
        return 0;
    return minswap;
}

int main(){
    int arr[] = {2, 7, 9, 5, 8, 7, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=5;
    cout<<swaps(arr,n,k);
    return 0;
}