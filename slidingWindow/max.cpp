#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={1, 3, -1, -3, 5, 3, 6, 7};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    int i=0,j=0;
    vector<int> ans;
    queue<int> maxNum;
    while(j<n){
        if(j-i+1<k){
            j++;
        }
        else if(j-i+1==k){
            for(int i=maxNum.front();i<=maxNum.back;i++){
                
            }
        }
    }
    return 0;
}