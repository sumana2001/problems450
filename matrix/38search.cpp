#include<bits/stdc++.h>
using namespace std;
#define r 4
#define c 4

bool search(int a[r][c],int m, int n,int k){
    int i=0,j=n-1;
    while (i<n && j>=0){
        if(k==a[i][j])
            return true;
        if(k>a[i][j])
            i++;
        else
            j--;
    }
    return false;
}

bool bsearch(int a[r][c],int m, int n,int k){
    int lo=0,hi=(m*n)-1;
    while(lo<=hi){
        int mid=lo+((hi-lo)/2);
        if(a[mid/n][mid%n]==k)
            return true;
        if(a[mid/n][mid%n]>k)
            hi=mid-1;
        else
            lo=mid+1;
    }
    return false;
}

int main(){
    int arr[r][c] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 15 },
                      { 18, 25, 27, 28 } };
    int k=15;
    cout<<search(arr,r,c,k)<<endl;
    cout<<bsearch(arr,r,c,k)<<endl;
    return 0;
}