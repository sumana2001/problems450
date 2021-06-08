#include <bits/stdc++.h>
using namespace std;

int heights(int arr[],int n,int k){
    sort(arr,arr+n);
    int min_ele,max_ele;
    int result=arr[n-1]-arr[0];
    for(int i=1;i<n;i++){
        max_ele=max(arr[n-1]-k,arr[i-1]+k);
        min_ele=min(arr[0]+k,arr[i]-k);
        result=min(result,max_ele-min_ele);
    }
    return result;
}

int main()
{
    int n,k;
    cin >> n>>k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter number: ";
        cin >> arr[i];
    }
    int result=heights(arr,n,k);
    cout<<result;
    return 0;
}