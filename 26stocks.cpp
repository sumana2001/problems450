#include<bits/stdc++.h>
using namespace std;

int maxProfit(int arr[],int n){
    int profit[n];
    for(int i=0;i<n;i++){
        profit[i]=0;
    }
    int max_price=arr[n-1];
    for(int i=n-2;i>=0;i--){
        if(arr[i]>max_price){
            max_price=arr[i];
        }
        profit[i]=max(profit[i+1],max_price-arr[i]);
    }
    int min_price=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]<min_price){
            min_price=arr[i];
        }
        profit[i]=max(profit[i-1],profit[i]+arr[i]-min_price);
    }
    return profit[n-1];
}

int main(){
    int arr[] = {100, 30, 15, 10, 8, 25, 80};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxProfit(arr,n);
    return 0;
}