#include<bits/stdc++.h>
using namespace std;

void solve(int arr[],int n){
    int i=0,j=n-1;
    while(i<=j){
        //both negative
        if(arr[i]<0 && arr[j]<0)
            i++;
        //i positive j negative
        else if(arr[i]>0 && arr[j]<0){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
        //both positive
        else if(arr[i]>0 && arr[j]>0)
            j++;
        //i negative j positive
        else{
            i++;
            j--;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter element: ";
        cin>>arr[i];
    }
    solve(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}