#include <bits/stdc++.h>
using namespace std;

int numberOfPaths1(int m, int n)
{
    if (m == 1 || n == 1)
        return 1;
    return numberOfPaths1(m - 1, n) + numberOfPaths1(m, n - 1);
}

int numberOfPaths2(int m, int n)
{
    int count[m][n];
    for (int i = 0; i < m; i++)
    {
        count[i][0] = 1;
    }
    for (int j = 0; j < n; j++)
    {
        count[0][j] = 1;
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            count[i][j] = count[i - 1][j] + count[i][j - 1];
        }
    }
    return count[m - 1][n - 1];
}

int main()
{
    cout << numberOfPaths2(3, 3);
    return 0;
}