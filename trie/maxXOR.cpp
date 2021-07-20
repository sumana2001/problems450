#include <bits/stdc++.h>
using namespace std;

// void bruteForce(){
//     int ans=0;
//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             if(arr[i]==arr[j])
//                 ans=max(arr[i],ans);
//             ans=max(arr[i]^arr[j],ans);
//         }
//     }
//     cout<<ans;
// }

class TrieNode
{
public:
    int value;
    TrieNode *arr[2];
    TrieNode()
    {
        value = 0;
        arr[0] = NULL;
        arr[1] = NULL;
    }
};

void insert(TrieNode *root, int preXOR)
{
    TrieNode *temp = root;
    for (int i = 31; i >= 0; i--)
    {
        bool val = preXOR & (1 << i);
        if (temp->arr[val] == NULL)
            temp->arr[val] = new TrieNode;
        temp = temp->arr[val];
    }
    temp->value = preXOR;
}

int query(TrieNode *root, int preXOR)
{
    TrieNode *temp = root;
    for (int i = 31; i >= 0; i--)
    {
        bool val = preXOR & (1 << i);
        if (temp->arr[1 - val] != NULL)
            temp = temp->arr[1 - val];
        else if (temp->arr[val] != NULL)
            temp = temp->arr[val];
    }
    return preXOR ^ (temp->value);
}

void maxXOR(int arr[], int n)
{
    TrieNode *root = new TrieNode;
    insert(root, 0);
    int result = INT_MIN, preXOR = 0;
    for (int i = 0; i < n; i++)
    {
        preXOR = preXOR ^ arr[i];
        insert(root, preXOR);
        result = max(result, query(root, preXOR));
    }
    cout << result;
}

int main()
{
    int arr[] = {8, 1, 2, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    maxXOR(arr, n);
    return 0;
}