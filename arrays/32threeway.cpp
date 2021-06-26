#include<bits/stdc++.h>
using namespace std;

void threeWayPartition(int arr[],int n, int low, int high){
    int start=0,end=n-1,i=0;
    while(i<end){
        if(arr[i]<low){
            swap(arr[start],arr[i]);
            start++;
            i++;
        }
        else if(arr[i]>high){
            swap(arr[end],arr[i]);
            end--;
        }
        else{
            ++i;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
    int n = sizeof(arr)/sizeof(arr[0]);
    int low=14,high=20;
    threeWayPartition(arr,n,low,high);
    return 0;
}