#include <bits/stdc++.h>
using namespace std;

void grayCode1(int n)
{
    for (int i = 0; i < (1 << n); i++)
    {
        int val = (i ^ (i >> 1));
        bitset<32> r(val);
        string s = r.to_string();
        cout << s.substr(32 - n) << " ";
    }
}

void grayCode2(int n)
{
    if (n <= 0)
        return;
    vector<string> v;
    v.push_back("0");
    v.push_back("1");
    int i, j;
    for (i = 2; i < (1 << n); i = i << 1)
    {
        for (j = i - 1; j >= 0; j--)
            v.push_back(v[j]);
        for (j = 0; j < i; j++)
            v[j] = "0" + v[j];
        for (j = i; j < 2 * i; j++)
            v[j] = "1" + v[j];
    }
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
}

int main()
{
    int n = 3;
    grayCode2(n);
    return 0;
}