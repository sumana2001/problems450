#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *next[26];
    bool end;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            next[i] = NULL;
        }
        end = false;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }
    void insert(string &s)
    {
        TrieNode *it = root;
        for (auto c : s)
        {
            if (!it->next[c - 'a'])
                it->next[c - 'a'] = new TrieNode();
            it = it->next[c - 'a'];
        }
        it->end = true;
    }
    void find(string &s)
    {
        TrieNode *it = root;
        for (auto c : s)
        {
            if (!it->next[c - 'a'])
            {
                cout << "Nothing here";
                insert(s);
                return;
            }
            it = it->next[c - 'a'];
        }
        vector<string> res;
        printall(it, s, res, "");
        for (auto c : res)
        {
            cout << s << c << endl;
        }
    }
    void printall(TrieNode *it, string &s, vector<string> &res, string curr)
    {
        if (it == NULL)
            return;
        if (it->end)
        {
            res.push_back(curr);
        }
        for (int i = 0; i < 26; i++)
        {
            if (it->next[i])
            {
                printall(it->next[i], s, res, curr + char('a' + i));
            }
        }
    }
};

int main()
{
    Trie t;
    string arr[] = {"blah", "behe", "bluh", "blie"};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        t.insert(arr[i]);
    }
    string s = "bl";
    t.find(s);
    return 0;
}