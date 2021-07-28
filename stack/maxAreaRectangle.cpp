//Max Area Rectangle in binary matrix
#include <bits/stdc++.h>
using namespace std;
#define n 4

vector<int> findNSL(int arr[])
{
    stack<pair<int, int> > s;
    vector<int> v;
    int pseudoIndex = -1;
    for (int i = 0; i < n; i++)
    {
        if (s.empty())
        {
            v.push_back(pseudoIndex);
        }
        else if (!s.empty() && s.top().first < arr[i])
        {
            v.push_back(s.top().second);
        }
        else if (!s.empty() && s.top().first >= arr[i])
        {
            while (!s.empty() && s.top().first >= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                v.push_back(pseudoIndex);
            }
            else
            {
                v.push_back(s.top().second);
            }
        }
        s.push(make_pair(arr[i], i));
    }
    return v;
}

vector<int> findNSR(int arr[])
{
    stack<pair<int, int> > s;
    vector<int> v;
    int pseudoIndex = n;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            v.push_back(pseudoIndex);
        }
        else if (!s.empty() && s.top().first < arr[i])
        {
            v.push_back(s.top().second);
        }
        else if (!s.empty() && s.top().first >= arr[i])
        {
            while (!s.empty() && s.top().first >= arr[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                v.push_back(pseudoIndex);
            }
            else
            {
                v.push_back(s.top().second);
            }
        }
        s.push(make_pair(arr[i], i));
    }
    reverse(v.begin(), v.end());
    return v;
}

int findMAH(int arr[])
{
    vector<int> nsl=findNSL(arr);
    vector<int> nsr=findNSR(arr);
    int width[n];
    int maxArea=0;
    for(int i=0;i<n;i++){
        width[i]=nsr[i]-nsl[i]-1;
        int area=width[i]*arr[i];
        maxArea=max(area,maxArea);
    }
    return maxArea;
}

int main()
{
    int arr[][n] = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};
    int v[n];
    for (int j = 0; j < n; j++)
    {
        v[j] = arr[0][j];
    }
    int mx = findMAH(v);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
                v[j] = 0;
            else
                v[j] += arr[i][j];
        }
        mx = max(mx, findMAH(v));
    }
    cout << mx;
    return 0;
}