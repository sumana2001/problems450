#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int n){
    sort(arr,arr+n);
    vector<int> v;
    v.push_back(arr[0]);
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] != arr[i - 1])
            v.push_back(arr[i]);
    }
    int maxlen=0;
    int curr=0;
    for(int i=0;i<v.size();i++){
        if(i>0 && v[i]-v[i-1]==1)
            curr++;
        else    
            curr=1;
        maxlen=max(curr,maxlen);
    }
    return maxlen;
}

int main(){
    int arr[] = {1, 9, 3, 10, 4, 20, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<solve(arr,n);
    return 0;
}