#include <bits/stdc++.h>
using namespace std;

void removeDups(string s)
{
    int arr[26];
    string res;
    for (int i = 0; i < 26; i++)
    {
        arr[i] = 0;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (arr[s[i] - 'a'] == 0)
        {
            res += s[i];
            arr[s[i] - 'a']++;
        }
    }
    cout << res;
}

int main()
{
    string s = "gfg";
    removeDups(s);
}