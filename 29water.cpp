#include<bits/stdc++.h>
using namespace std;

int trapWater(int arr[],int n){
    int left[n],right[n];
    int water=0;
    left[0]=arr[0];
    for(int i=1;i<n;i++){
        left[i]=max(left[i-1],arr[i]);
    }
    right[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        right[i]=max(right[i+1],arr[i]);
    }
    for(int i=0;i<n;i++){
        water+=min(left[i],right[i])-arr[i];
    }
    return water;
}

int trapWater2(int arr[], int n){
    int water = 0;
    int left_max=0,right_max=0;
    int lo=0,hi=n-1;
    while(lo<=hi){
        if(arr[lo]<arr[hi]){
            if(arr[lo]>left_max)
                left_max=arr[lo];
            else
                water+=left_max-arr[lo];
            lo++;
        }
        else{
            if(arr[hi]<arr[lo]){
                if(arr[hi]>right_max)
                    right_max=arr[hi];
                else
                    water+=right_max-arr[hi];
                hi--;
            }
        }
    }
    return water;
}

int main(){
    int arr[] = {3, 0, 2, 0, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<trapWater(arr,n);
    return 0;
}