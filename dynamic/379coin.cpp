//Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins.
#include<bits/stdc++.h>
using namespace std;

int coinChange(int arr[],int n,int k){
    if(k<0)
        return 0;
    if(n<=0 && k>=1)
        return 0;
    int table[k+1][n];
    for(int i=0;i<k+1;i++){
        table[0][i]=1;
    }
    for(int i=1;i<k+1;i++){
        for(int j=0;j<n;j++){
            int x=(i-arr[j]>=0)?table[i-arr[j]][j]:0;
            int y=(j>=1)?table[i][j-1]:0;
            table[i][j]=x+y;
        }
    }
    return table[k][n-1];
}

int main(){
    int arr[]={1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=4;
    cout<<coinChange(arr,n,k);
    return 0;
}