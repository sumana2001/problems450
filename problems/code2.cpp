#include <bits/stdc++.h>
#include<vector>
using namespace std;

int main()
{
    int arr[] = { 1, 0, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    vector<int> vect(arr, arr + n);
 
    for (int x : vect)
        cout << x << " ";
 
    int num=0;
    for(int x : vect)
        num=(num*10)+x;
    cout<<num;

    return 0;
}

// v=[3,2,1,0]
// 3210