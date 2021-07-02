#include<bits/stdc++.h>
using namespace std;
#define r 4
#define c 4

void sort(int arr[r][c]){
    int k=0;
    int n=r*c;
    int arr1[n];
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            arr1[k++]=arr[i][j];
    sort(arr1,arr1+k);
    k=0;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            arr[i][j]=arr1[k++];
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cout<<arr[i][j]<<" ";
}

int main(){
    int arr[r][c] = { {10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50} };
    sort(arr);
    return 0;
}