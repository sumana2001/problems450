#include<bits/stdc++.h>
using namespace std;

int jumps(int arr[],int n){
    if(n<=1)
        return 0;
    if(arr[0]==0)
        return -1;
    int maxReach=arr[0];
    int step=arr[0];
    int jump=1;
    for(int i=1;i<n;i++){
        if(i==n-1)
            return jump;
        maxReach=max(maxReach,arr[i]+i);
        step--;
        if(step==0){
            jump++;
            if(i>=maxReach)
                return -1;
            step=maxReach-i;
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter number: ";
        cin>>arr[i];
    }
    int result=jumps(arr,n);
    cout<<result;
    return 0;
}