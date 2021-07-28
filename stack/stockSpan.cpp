#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {100, 80, 60, 70, 60, 75, 85};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int> v;
    stack<pair<int, int> > s;
    for(int i=0;i<n;i++){
        if(s.empty()){
            v.push_back(1);
        }
        else if(!s.empty() && s.top().first>arr[i]){
            v.push_back(i-(s.top().second));
        }
        else if(!s.empty() && s.top().first<=arr[i]){
            while(!s.empty() && s.top().first<=arr[i]){
                s.pop();
            }
            if(s.size()==0){
                v.push_back(1);
            }
            else{
                v.push_back(i-(s.top().second));
            }
        }
        s.push(make_pair(arr[i],i));
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}