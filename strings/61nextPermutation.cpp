#include<bits/stdc++.h>
using namespace std;

void rev(int arr[], int l, int r){
    while(l<r){
        swap(arr[l++],arr[r--]);
    }
}

void nextPermute(int arr[],int n){
    int index1=-1,index2=-1;
    for(int i=n-1;i>0;i--){
        if(arr[i]>arr[i-1]){
            index1=i-1;
            break;
        }
    }
    if(index1==-1){
        sort(arr,arr+n);
        return;
    }
    for(int i=n-1;i>=0;i--){
        if(arr[i]>arr[index1]){
            index2=i;
            break;
        }
    }
    swap(arr[index1],arr[index2]);
    rev(arr,index1+1,n-1);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    nextPermute(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;
}