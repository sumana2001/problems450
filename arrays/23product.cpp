#include<bits/stdc++.h>
using namespace std;

int maxproduct(int arr[], int n){
    int maxprod=arr[0];
    int maxval=arr[0];
    int minval=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]<0)
            swap(maxval,minval);
        maxval=max(arr[i],maxval*arr[i]);
        minval=min(arr[i],minval*arr[i]);
        maxprod=max(maxprod,maxval);
    }
    return maxprod;

}

int main(){
    int arr[] = {2, 3, 4, 5, -1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxproduct(arr,n);
    return 0;
}