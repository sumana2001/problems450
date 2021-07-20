#include <bits/stdc++.h>
using namespace std;

class Trie
{
public:
    class Node
    {
    public:
        bool end;
        Node *next[26];
        Node()
        {
            end = false;
            for (int i = 0; i < 26; i++)
            {
                next[i] = NULL;
            }
        }
    };
    Node *trie;
    Trie()
    {
        trie = new Node();
    }
    void insert(string word)
    {
        int i = 0;
        Node *it = trie;
        while (i < word.size())
        {
            if (it->next[word[i] - 'a'] == NULL)
                it->next[word[i] - 'a'] = new Node();
            it = it->next[word[i] - 'a'];
            i++;
        }
        it->end = true;
    }
    bool search(string word)
    {
        int i = 0;
        Node *it = trie;
        while (i < word.size())
        {
            if (it->next[word[i] - 'a'] == NULL)
                return false;
            it = it->next[word[i] - 'a'];
            i++;
        }
        return it->end;
    }
};

int main()
{
    Trie myTrie;
    string words[] = {"blah", "bluh", "blih"};
    int n = sizeof(words) / sizeof(words[0]);
    for (int i = 0; i < n; i++)
    {
        myTrie.insert(words[i]);
    }
    if (myTrie.search("blah"))
        cout << "YEP" << endl;
    else
        cout << "NOPE" << endl;
    if (myTrie.search("hehe"))
        cout << "YEP" << endl;
    else
        cout << "NOPE" << endl;
    return 0;
}