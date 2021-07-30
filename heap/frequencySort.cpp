#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={1,1,3,1,3,2,2,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    priority_queue<pair<int,int> > pq;
    for(auto i=mp.begin();i!=mp.end();i++){
        pq.push(make_pair(i->second,i->first));
    }
    while(!pq.empty()){
        for(int i=0;i<pq.top().first;i++){
            cout<<pq.top().second<<" ";
        }
        pq.pop();
    }
    return 0;
}