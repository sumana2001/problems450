#include<bits/stdc++.h>
using namespace std;

int main(){
    int start=0,mid=0,end=5;
    int arr[]={0,3,2,7,4,1};
    while(mid<=end){
        if(arr[mid]==0){
            swap(arr[start++],arr[mid++]);
            cout<<mid;
            break;
        }

    }
    return 0;
}