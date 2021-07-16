#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 3, 5, 5, 5, 5, 7, 123, 125};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 7, i = 0;
    vector<int> result;
    for (i; i < n; i++)
    {
        if (arr[i] == x)
        {
            result.push_back(i);
            break;
        }
    }
    i = i + 1;
    for (i; i < n; i++)
    {
        if (arr[i] != x)
        {
            result.push_back(i - 1);
            break;
        }
    }
    if (result.size() == 0)
    {
        cout << "Element not found" << endl;
        return 0;
    }
    for (int j = 0; j < result.size(); j++)
    {
        cout << result[j] << endl;
    }
    return 0;
}