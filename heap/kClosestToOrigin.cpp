#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int> > ppi;

int main(){
    int arr[][2]={{1,3},{-2,2},{5,8},{0,1}};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=2;
    priority_queue<ppi> pq;
    for(int i=0;i<n;i++){
        int num=pow(arr[i][0],2)+pow(arr[i][1],2);
        pq.push(make_pair(num,make_pair(arr[i][0],arr[i][1])));
        if(pq.size()>k){
            pq.pop();
        }
    }
    while(!pq.empty()){
        cout<<"{"<<pq.top().second.first<<","<<pq.top().second.second<<"} ";
        pq.pop();
    }
    return 0;
}