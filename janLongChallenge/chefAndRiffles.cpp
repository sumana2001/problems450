#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll Add(ll n, ll m, ll k)
{
    n = n % k;
    m = m % k;
    return (((n + m) % k) + k) % k;
}

ll Mul(ll n, ll m, ll k)
{
    n = n % k;
    m = m % k;
    return (((n * m) % k) + k) % k;
}

ll Sub(ll n, ll m, ll k)
{
    n = n % k;
    m = m % k;
    return (((n - m) % k) + k) % k;
}

ll expo(ll n, ll m, ll mod)
{
    ll ans = 1;
    while (m > 0)
    {
        if (m & 1)
            ans = (ans * n) % mod;
        n = (n * n) % mod;
        m = m >> 1;
    }
    return ans;
}

void solve(int n, int k)
{
    vector<ll> ans(n);
    for (int i = 1; i <= n; i++)
    {
        ans[i - 1] = i;
    }
    ll count = 0;
    ll g = 2;
    while (1)
    {
        count++;

        if (g & 1)
            g = (g + 1) / 2;
        else
            g = ((g / 2) + (n / 2));
        if (g == 2)
            break;
    }
    k %= count;
    ll tmp = Sub(expo(2, k, n - 1), 1, n - 1);
    ll fac;
    for (int i = 1; i <= n - 2; i++)
    {
        fac = Mul(tmp, i, n - 1);
        ans[i] = Add(ans[i], fac, n - 1);
        if (ans[i] == 0)
            ans[i] = n - 1;
    }

    for (auto &x : ans)
        cout << x << " ";
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        solve(n, k);
        cout << "\n";
    }
    return 0;
}