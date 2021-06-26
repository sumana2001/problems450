#include<bits/stdc++.h>
using namespace std;

void solvesort(int arr[],int n,int k){
    int x=n/k;
    sort(arr,arr+n);
    int count=1;
    for(int i=0;i<n;i++){
        if(arr[i]!=arr[i+1]){
            if(count>x)
                cout<<arr[i]<<" "<<count<<endl;
            count=1;
        }
        else
            count++;
    }
}

void solvehash(int arr[],int n,int k){
    int x=n/k;
    map<int,int> m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    for(auto i:m){
        if(i.second>x){
            cout<<i.first<<" "<<i.second<<endl;
        }
    }
}

int main(){
    int arr[] = {3, 1, 2, 2, 1, 2, 3, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    solvehash(arr,n,k);
    return 0;
}