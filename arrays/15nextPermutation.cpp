#include<bits/stdc++.h>
using namespace std;

void solveSTL(int arr[],int n){
    bool val=next_permutation(arr,arr+n);
    if(val==false){
        sort(arr,arr+n);
    }
}

int bsearch(int s[],int l, int r, int key){
        int index = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (s[mid] <= key)
            r = mid - 1;
        else {
            l = mid + 1;
            if (index == -1 || s[index] >= s[mid])
                index = mid;
        }
    }
    return index;
}

void rev(int s[], int l, int r)
{
    while (l < r)
        swap(s[l++], s[r--]);
}
  

void solve(int arr[],int n){
    int i=n-2;
    while(i>=0 && arr[i]>=arr[i+1])
        --i;
    if(i<0)
        sort(arr,arr+n);
    else{
        int index=bsearch(arr,i+1,n-1,arr[i]);
        swap(arr[i],arr[index]);
        rev(arr, i + 1, n - 1);
    }
}


int main(){
    int arr[]={1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    solve(arr,n);
    cout<<"Output: {";
    for(int i=0;i<n-1;i++)
        cout<<arr[i]<<",";
    cout<<arr[n-1]<<"}";
    return 0;
}
