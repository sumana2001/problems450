#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {2, 4, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n - 1; i += 2)
    {
        swap(arr[i], arr[i + 1]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}