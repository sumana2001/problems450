#include <bits/stdc++.h>
using namespace std;
#define n 5

int main()
{
    int max_so_far = INT_MIN;
    int arr[n][n] = {{1, 2, -1, -4, -20}, {-8, -3, 4, 2, 1}, {3, 8, 6, 1, 3}, {-4, -1, 1, 7, -6}, {0, -4, 10, -5, 1}};
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; i < n - 1; j++)
        {
            for (int k = i + 1; k < n; k++)
            {
                for (int l = j + 1; l < n; l++)
                {
                    if (max_so_far < (arr[k][l] - arr[i][j]))
                        max_so_far = arr[k][l] - arr[i][j];
                }
            }
        }
    }
    cout << max_so_far;
    return 0;
}
