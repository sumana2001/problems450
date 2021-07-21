#include <bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes(int n)
{
    int count = 0;
    while (n != 0)
    {
        n = n & (n << 1);
        count++;
    }
    return count;
}

int main()
{
    cout << maxConsecutiveOnes(222) << endl;
    return 0;
}