//Maximum Area Histogram
#include <bits/stdc++.h>
using namespace std;

vector<int> findNSL(int arr[], int n)
{
    stack<pair<int, int> > s;
    vector<int> v;
    int pseudoIndex=-1;
    for(int i=0;i<n;i++){
        if(s.empty()){
            v.push_back(pseudoIndex);
        }
        else if(!s.empty() && s.top().first<arr[i]){
            v.push_back(s.top().second);
        }
        else if(!s.empty() && s.top().first>=arr[i]){
            while(!s.empty() && s.top().first>=arr[i]){
                s.pop();
            }
            if(s.size()==0){
                v.push_back(pseudoIndex);
            }
            else{
                v.push_back(s.top().second);
            }
        }
        s.push(make_pair(arr[i],i));
    }
    return v;
}

vector<int> findNSR(int arr[], int n)
{
    stack<pair<int, int> > s;
    vector<int> v;
    int pseudoIndex=n;
    for(int i=n-1;i>=0;i--){
        if(s.empty()){
            v.push_back(pseudoIndex);
        }
        else if(!s.empty() && s.top().first<arr[i]){
            v.push_back(s.top().second);
        }
        else if(!s.empty() && s.top().first>=arr[i]){
            while(!s.empty() && s.top().first>=arr[i]){
                s.pop();
            }
            if(s.size()==0){
                v.push_back(pseudoIndex);
            }
            else{
                v.push_back(s.top().second);
            }
        }
        s.push(make_pair(arr[i],i));
    }
    reverse(v.begin(),v.end());
    return v;
}

int main()
{
    int arr[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> nsl = findNSL(arr, n);
    vector<int> nsr = findNSR(arr, n);
    int width[n];
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        width[i] = nsr[i]-nsl[i]-1;
        int area = width[i] * arr[i];
        if (area > maxArea)
            maxArea = area;
    }
    cout << maxArea;
    return 0;
}