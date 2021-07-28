//k1th smallest, k2th smallest
//sum of nos between k1 and k2
//arr[]={4,2,3,6,1,5}
//k1=2,k2=5
//2+3+4+5=14

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {4, 2, 3, 6, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k1 = 1, k2 = 3;
    int sum=0;
    priority_queue <int, vector<int>, greater<int> > pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    int i=1;
    while(i<min(k1,k2)){
        pq.pop();
        i++;
    }
    while(i<=max(k1,k2)){
        sum+=pq.top();
        pq.pop();
        i++;
    }
    cout<<sum<<endl;
    return 0;
}