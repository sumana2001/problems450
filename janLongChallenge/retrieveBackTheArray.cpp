#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5;

void solve()
{
    ll n, k;
    cin >> n >> k;
    if (n == 1)
    {
        cout << k << "\n";
        return;
    }
    if (n == 2)
    {
        cout << 0 << " " << k << "\n";
        return;
    }

    vector<ll> result;
    ll max = 400000;
    for (ll i = 0; i <= N; i++)
    {
        if (result.size() == n - 2)
            break;

        result.push_back(i);
    }
    result.push_back(max);
    result.push_back(max);

    ll cnt = 0;
    for (ll i = 18; i >= 0; i--)
    {
        ll sum = 0;
        for (auto &c : result)
        {
            sum += ((c >> i) & 1);
        }
        if (((k >> i) & 1) == 0 && (sum & 1) == 1 || (((k >> i) & 1) == 1) && (sum & 1) == 0)
        {
            if (cnt & 1)
            {
                result[result.size() - 2] ^= (1ll << i);
            }
            else
            {
                result[result.size() - 1] ^= (1ll << i);
            }
            cnt++;
        }
    }

    multiset<ll> sets;
    for (auto &c : result)
    {
        sets.insert(c);
    }
    if (result[result.size() - 2] == result[result.size() - 1])
    {
        bool flag = 0;
        for (int g = 0; g <= 18; g++)
        {
            if (((result.back() >> g) & 1))
            {
                for (auto &c : result)
                {
                    if ((((c >> g) & 1)) == 0)
                    {

                        c ^= (1ll << g);
                        if (sets.find(c) != sets.end() || c > N)
                        {
                            c ^= (1ll << g);
                            continue;
                        }
                        result.back() ^= (1ll << g);
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag)
                break;
        }
    }
    for (auto &c : result)
    {
        cout << c << " ";
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}