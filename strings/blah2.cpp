
#include<bits/stdc++.h>
using namespace std;

bool check(string arr[], int n, string key){
    int count=0;
    for(int i=0;i<n;i++){
        if(key==arr[i])
            count++;
        if(count>=2)
            return true;
    }
    return false;
}

int main(){
    int n=4;
    string arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        if(check(arr,n,arr[i])==false)
            cout<<arr[i]<<" ";
    }
    return 0;
}