#include<bits/stdc++.h>
using namespace std;

int bsearch(int arr[],int n,int target){
    int v;
    int l=0;
    int r=n-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(arr[l]<=arr[mid]){
            if(arr[l]<=target && arr[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        else{
            if(arr[mid]<target && arr[r]>=target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
    }
    return -1;
}

int main(){
    int arr[]={4,5,6,7,0,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=5;
    cout<<bsearch(arr,n,target);
    return 0;
}