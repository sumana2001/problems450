#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *next[26];
    bool end;
    Node()
    {
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
        end = false;
    }
};

void insert(string s, Node *trie)
{
    int i = 0;
    Node *it = trie;
    while (i < s.size())
    {
        if (it->next[s[i] - 'a'] == NULL)
            it->next[s[i] - 'a'] = new Node();
        it = it->next[s[i] - 'a'];
        i++;
    }
    it->end = true;
}

int search(string s, Node *trie)
{
    int i = 0;
    Node *it = trie;
    while (i < s.size())
    {
        if (it->next[s[i] - 'a'] == NULL)
            return 0;
        it = it->next[s[i] - 'a'];
        i++;
    }
    if (it->end == true)
        return 1;
    return 0;
}

int main()
{
    Node *trie = new Node();
    string arr[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        insert(arr[i], trie);
    }
    cout << search("there", trie);
    return 0;
}