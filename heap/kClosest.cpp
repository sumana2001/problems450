#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={6, 5, 3, 2, 8, 10, 9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x=5;
    int k=3;
    priority_queue<pair<int,int> > pq;
    for(int i=0;i<n;i++){
        int diff=abs(x-arr[i]);
        pq.push(make_pair(diff,arr[i]));
        if(pq.size()>k){
            pq.pop();
        }
    }
    while(!pq.empty()){
        cout<<pq.top().second<<" ";
        pq.pop();
    }
    return 0;
}