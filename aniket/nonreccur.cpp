#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int count=0;
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count==0){
            return arr[i];
        }
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<solve(arr,n);
    return 0;
}
