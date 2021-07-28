//Rain Water Trapping
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={3,0,0,2,0,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int maxL[n];
    int maxR[n];
    int sum=0;
    maxL[0]=arr[0];
    for(int i=1;i<n;i++){
        maxL[i]=max(maxL[i-1],arr[i]);
    }
    maxR[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        maxR[i]=max(maxR[i+1],arr[i]);
    }
    for(int i=0;i<n;i++){
        int water=min(maxL[i],maxR[i])-arr[i];
        sum+=water;
    }
    cout<<sum;
    return 0;
}