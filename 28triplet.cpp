#include<bits/stdc++.h>
using namespace std;

bool triplet(int arr[],int n,int sum){
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        int l=i+1;
    int r=n-1;
        while(l<r){
            if(arr[i]+arr[l]+arr[r]==sum){
                cout<<arr[i]<<" "<<arr[l]<<" "<<arr[r]<<endl;
                return true;
            }
            else if(arr[i]+arr[l]+arr[r]>sum)
                r--;
            else
                l++;
        }
    }
    return false;
}

int main(){
    int arr[] = {1, 4, 45, 6, 10, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum=13;
    bool result=triplet(arr,n,sum);;
    if(result)
        cout<<"Yes";
    else    
        cout<<"No";
    return 0;
}