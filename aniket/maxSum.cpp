#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={1,2,3,4,-2,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    int maxSum=INT_MIN;
    int currSum=arr[0];
    int i=0,j=1;
    while(j<n){
        currSum+=arr[j];
        if(j-i+1<k)
            j++;
        else if(j-i+1==k){
            if(currSum>maxSum){
                maxSum=currSum;
            }
            j++;
            currSum-=arr[i];
            i++;
        }
    }
    cout<<maxSum;
    return 0;
}