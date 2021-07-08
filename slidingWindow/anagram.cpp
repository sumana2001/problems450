#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1 = "aabaabaa";
    string s2 = "aaba";
    int n = s1.length();
    int k = s2.length();
    map<char, int> m;
    for (int l = 0; l < k; l++)
    {
        m[s2[l]]++;
    }
    int count = m.size();
    int ans = 0, i = 0, j = 0;
    while (j < n)
    {
        m[s1[j]]--;
        if (m[s1[j]] == 0)
        {
            count--;
        }
        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            if (count == 0)
            {
                ans++;
            }
            if (m[s1[i]] == 0)
            {
                count++;
                m[s1[i]]++;
            }
            i++;
            j++;
        }
    }
    cout << ans;
    return 0;
}