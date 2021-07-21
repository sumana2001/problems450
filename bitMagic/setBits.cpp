#include <bits/stdc++.h>
using namespace std;

void method1(int n)
{
    unsigned int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    cout << count;
}

void method2(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    cout << count;
}

int main()
{
    int n = 9;
    method2(n);
    return 0;
}