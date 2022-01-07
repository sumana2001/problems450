#include<bits/stdc++.h>
using namespace std;

int sum(int arr[],int start,int end){
    int total=0;
    while(start<=end){
        total+=arr[start];
        start++;
    }
    return total;
}

void naive(int arr[],int n){
    for(int i=1;i<n;i++){
        int lsum=sum(arr,0,i-1);
        int rsum=sum(arr,i+1,n-1);
        if(lsum==rsum){
            cout<<arr[i]<<endl;
            break;
        }
    }
}

void prefix(int arr[],int n){
    int prefix[n];
    prefix[0]=arr[0];
    int suffix[n];
    suffix[n-1]=arr[n-1];
    for(int i=1;i<n;i++){
        prefix[i]=arr[i]+prefix[i-1];
    }
    for(int i=n-2;i>=0;i--){
        suffix[i]=arr[i]+suffix[i+1];
    }
    for(int i=0;i<n;i++){
        if(suffix[i]==prefix[i]){
            cout<<arr[i]<<endl;
            break;
        }
    }
}

void best(int arr[],int n){
    int lsum=0,rsum=0;
    for(int i=1;i<n;i++){
        rsum+=arr[i];
    }
    for(int i=0,j=1;j<n;i++,j++){
        lsum+=arr[i];
        rsum-=arr[j];
        if(lsum==rsum){
            cout<<arr[j]<<endl;
            break;
        }
    }
}

int main(){
    int arr[]={2, 3, 4, 1, 4, 5};
    int n=sizeof(arr)/sizeof(arr[0]);
    naive(arr,n);
    prefix(arr,n);
    best(arr,n);
    return 0;
}