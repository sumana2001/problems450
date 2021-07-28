#include<bits/stdc++.h>
using namespace std;

void solve1(int arr[],int n,int k){
    sort(arr,arr+n);
    cout<<arr[n-k];
}

void solve2(int arr[],int n,int k){
    if(n<k){
        cout<<"Wrong input";
        return;
    }
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    for(int i=0;i<k-1;i++){
        pq.pop();
    }
    cout<<pq.top();
}

int main(){
    int arr[]={2,4,3,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=2;
    solve2(arr,n,k);
    return 0;
}