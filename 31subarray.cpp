#include<bits/stdc++.h>
using namespace std;

int minSum(int arr[],int n,int x){
    int curr = 0, minlen = n + 1;
    int start = 0, end = 0;
    while (end < n) {
        while (curr <= x && end < n)
            curr += arr[end++];
        while (curr > x && start < n) {
            if (end - start < minlen)
                minlen = end - start;
            curr -= arr[start++];
        }
    }
    return minlen;
}

int main(){
    int arr[] = {1, 4, 45, 6, 0, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x=51;
    cout<<minSum(arr,n,x);
    return 0;
}