#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={1, 4, 2, 10, 2, 3, 1, 0, 20};
    int n=9,k=4,i=0,j=i+k;
    int curr=0,maxSum=0;
    for(int i=0;i<j;i++){
        curr+=arr[i];
    }
    maxSum=curr;
    while(j<n){
        curr=curr-arr[i]+arr[j];
        maxSum=max(curr,maxSum);
        i++;
        j++;
    }
    cout<<maxSum;
    return 0;
}