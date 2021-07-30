#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 23, 12, 9, 30, 2, 50};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    priority_queue < int , vector<int>, greater<int> > pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        if(pq.size()>k){
            pq.pop();
        }
    }
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    return 0;
}