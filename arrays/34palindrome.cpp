#include <bits/stdc++.h>
using namespace std;

bool palin(int arr[], int n)
{
    int count=0;
    for (int i = 0; i < n; i++)
    {
        int rev = 0;
        int current=arr[i];
        while (current > 0)
        {
            rev = rev * 10 + current % 10;
            current /= 10;
        }
        if (rev == arr[i])
            count++;
    }
    if(count==n)
        return true;
    return false;
}

int main()
{
    int arr[] = {111,222,333,20,555};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result=palin(arr, n);
    if(result)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}