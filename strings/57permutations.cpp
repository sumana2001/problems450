#include <bits/stdc++.h>
using namespace std;
set<string> m;

void permute(string s, int l, int r)
{
    if (l == r)
    {
        cout << s << endl;
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(s[i], s[l]);
            permute(s, l + 1, r);
            swap(s[i], s[l]);
        }
    }
}

void permute2(string s, int l, int r)
{
    if (l == r)
    {
        m.insert(s);
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(s[i], s[l]);
            permute2(s, l + 1, r);
            swap(s[i], s[l]);
        }
    }
}

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    permute(s, 0, n - 1);
    cout<<endl;
    permute2(s, 0, n - 1);
    for (auto it = m.begin(); it !=m.end();++it)
        cout << *it<<endl;
    return 0;
}