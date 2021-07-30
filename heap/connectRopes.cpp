#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={4,3,2,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=0;
    priority_queue<int,vector<int>,greater<int> > pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    while(pq.size()>=2){
        int first=pq.top();
        pq.pop();
        int second=pq.top();
        pq.pop();
        pq.push(first+second);
        sum=sum+first+second;
    }
    cout<<sum;
    return 0;
}