#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[],int n,int k){
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        if(pq.size()>k){
            pq.pop();
        }
    }
    return pq.top();
}

int main(){
    int arr[]={20, 8, 22, 4, 12, 10, 14};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k1=3;
    int k2=6;
    int num1=kthSmallest(arr,n,k1);
    int num2=kthSmallest(arr,n,k2);
    int sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]>num1 && arr[i]<num2){
            sum+=arr[i];
        }
    }
    cout<<sum;
    return 0;
}