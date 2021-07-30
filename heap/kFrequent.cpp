#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;

int main(){
    int arr[]={1,1,1,3,2,2,4};
    int k=2;
    int n=sizeof(arr)/sizeof(arr[0]);
    map<int,int> m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    priority_queue<p,vector<p>,greater<p> > pq;
    for(auto i=m.begin();i!=m.end();i++){
        pq.push(make_pair(i->second,i->first));
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