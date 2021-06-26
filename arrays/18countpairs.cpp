#include<bits/stdc++.h>
using namespace std;

int solveBrute(int arr[],int n,int k){
    int count=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==k)
                count++;
        }
    }
    return count;
}

int solve(int arr[], int n, int k){
    map<int, int> m;
    for(int i=0;i<n;i++)
        m[arr[i]]++;
    int count=0;
    for(int i=0;i<n;i++){
        count+=m[k-arr[i]];
        if(k-arr[i]==arr[i])
            count--;
    }
    return count/2;
}

int main(){
    int arr[] = {1, 5, 7, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=6;
    cout<<solve(arr,n,k);
    return 0;
}