#include<bits/stdc++.h>
using namespace std;

int median(int arr[],int n){
    sort(arr,arr+n);
    if(n%2!=0)
        return arr[((n+1)/2)-1];
    else
        return (arr[(n/2)-1]+arr[((n+1)/2)])/2;
}

int main(){
    int arr1[] = {-5, 3, 6, 12, 15};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {-12, -10, -6, -3, 4, 10};
    int m = sizeof(arr2)/sizeof(arr2[0]);
    int arr3[n+m];
    for(int i=0;i<n;i++)
        arr3[i]=arr1[i];
    for(int i=0;i<m;i++)
        arr3[i+n]=arr2[i];
    sort(arr3,arr3+(n+m));
    cout<<median(arr3,n+m);
    return 0;
}