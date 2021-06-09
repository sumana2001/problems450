#include<bits/stdc++.h>
using namespace std;

void merge(int arr1[],int arr2[],int n,int m){
    int i=0;
    while(arr1[n-1]>arr2[0]){
        if(arr1[i]>arr2[0]){
            swap(arr1[i],arr2[0]);
            sort(arr2,arr2+m);
        }
    i++;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int arr1[n], arr2[m];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter number in 1st array: ";
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cout << "Enter number in 2nd array: ";
        cin >> arr2[i];
    }
    merge(arr1,arr2,n,m);
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i]<<" ";
    }
    for (int i = 0; i < m; i++)
    {
        cout << arr2[i]<<" ";
    }
    return 0;
}