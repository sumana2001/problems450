#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *next[2];
    TrieNode()
    {
        next[0] = NULL;
        next[1] = NULL;
    }
};

TrieNode *trie;

void insert(int num)
{
    TrieNode *it = trie;
    for (int i = 31; i >= 0; i--)
    {
        int curr = (num >> i) & 1;
        if (!it->next[curr])
        {
            it->next[curr] = new TrieNode();
        }
        it = it->next[curr];
    }
}

int query(int num)
{
    TrieNode *it = trie;
    int ans = 0;
    for (int i = 31; i >= 0; i--)
    {
        int curr = (num >> i) & 1;
        int opp = curr xor 1;
        if (it->next[opp])
        {
            it = it->next[opp];
            ans |= 1 << i;
        }
        else
        {
            it = it->next[opp xor 1];
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 2, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    trie = new TrieNode();
    insert(0);
    vector<int> rmax(n + 1, 0);
    int R = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        R = R xor arr[i];
        if (i != n - 1)
        {
            rmax[i] = max(rmax[i + 1], query(R));
            insert(R);
        }
        else
        {
            rmax[i] = query(R);
            insert(R);
        }
    }
    free(trie);
    trie = new TrieNode();
    insert(0);
    int ans = 0;
    int L = 0;
    for (int i = 0; i < n; i++)
    {
        L = L ^ arr[i];
        ans = max(ans, rmax[i + 1] + query(L));
        insert(L);
    }
    cout << ans;
    return 0;
}