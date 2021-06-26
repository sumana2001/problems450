#include <bits/stdc++.h>
using namespace std;

void iSolve(int arr[], int n)
{
    int start = 0, end = n - 1;
    while (start < end)
    {
        int temp;
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rSolve(int arr[], int start, int end)
{
    if (start >= end)
        return;
    int temp;
    temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    rSolve(arr,start+1,end-1);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element: ";
        cin >> arr[i];
    }
    rSolve(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    return 0;
}
