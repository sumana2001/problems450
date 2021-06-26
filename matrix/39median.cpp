#include<bits/stdc++.h>
using namespace std;
#define r 3
#define c 3

int median(int arr[r][c], int m, int n){
    int min=INT_MAX,max=INT_MIN;
    for(int i=0;i<m;i++){
        if(arr[i][0]<min)
            min=arr[i][0];
        if(arr[i][n-1]>max)
            max=arr[i][n-1];
    }
    int desired=(m*n+1)/2;
        while (min < max)
    {
        int mid = min + (max - min) / 2;
        int place = 0;
        for (int i = 0; i < m; ++i)
            place += upper_bound(arr[i], arr[i]+n, mid) - arr[i];
        if (place < desired)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}

int main(){
    int arr[r][c] = { {1,3,5}, {2,6,9}, {3,6,9} };
    cout<<median(arr,r,c);
    return 0;
}