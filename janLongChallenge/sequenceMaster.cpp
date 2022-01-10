#include <bits/stdc++.h>
using namespace std;



int countUnique(vector<int> v, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (v[i] == v[j])
            {
                count++;
            }
            else
            {
                count += 2;
            }
        }
    }
    return count;
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> v;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
        s.insert(num);
    }
    while (q--)
    {
        int query;
        cin >> query;
        if (query == 1)
        {
            int a, b;
            cin >> a >> b;
            v[a - 1] = b;
        }
        else
        {
            int a;
            cin >> a;
            int result=a+((a-1)*a)-(a-s.size());
            cout<<result<<"\n";
        }
    }
    return 0;
}
