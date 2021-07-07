#include <bits/stdc++.h>
using namespace std;
set<string> m;

void permute(string s, int l, int r)
{
    if (l == r)
    {
        m.insert(s);
    }
    for (int i = l; i <= r; i++)
    {
        swap(s[i], s[l]);
        permute(s, l + 1, r);
        swap(s[i], s[l]);
    }
}

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    permute(s, 0, n - 1);
    cout<<m.size()<<endl;
    for (auto i = m.begin(); i != m.end(); i++)
    {
        cout << *i << endl;
    }
    return 0;
}
