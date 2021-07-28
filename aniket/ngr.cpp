//arr[]={3,5,4,7,1}
//arr1[]={5,7,7,-1,-1}

#include <bits/stdc++.h>
using namespace std;

void solve1(int arr[], int n)
{
    int res[n];
    for (int i = 0; i < n; i++)
    {
        res[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                res[i] = arr[j];
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
}

void solve2(int arr[], int n)
{
    int res[n];
    stack<pair<int, int> > s;
    s.push(make_pair(arr[0],0));
    for(int i=1;i<n;i++){
        int temp=arr[i];
        while(!s.empty() && s.top().first<temp){
            int index=s.top().second;
            res[index]=temp;
            s.pop();
        }
        s.push(make_pair(temp,i));
    }
    while(!s.empty()){
        int index=s.top().second;
        res[index]=-1;
        s.pop();
    }
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
}

int main()
{
    int arr[] = {3, 5, 4, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    solve2(arr, n);
    return 0;
}