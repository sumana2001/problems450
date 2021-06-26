#include<bits/stdc++.h>
using namespace std;

int solvebrute(int arr[],int n){
    int max_profit=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int profit=arr[j]-arr[i];
            if(max_profit<profit)
                max_profit=profit;
        }
    }
    return max_profit;
}

int solve(int arr[],int n){
    int max_profit=0;
    int min_price=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<min_price)
            min_price=arr[i];
        else if(arr[i]-min_price>max_profit){
            max_profit=arr[i]-min_price;
        }
    }
    return max_profit;
}

int main(){
    int arr[] = {7,1,5,3,6,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<solve(arr,n);
    return 0;
}