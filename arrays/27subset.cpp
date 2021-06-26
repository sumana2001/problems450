#include<bits/stdc++.h>
using namespace std;

bool subsetCheckSet(int arr1[],int arr2[], int n, int m){
    if(m>n)
        return false;
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(arr1[i]);
    }
    int s1_size=s.size();
    for(int i=0;i<m;i++){
        s.insert(arr2[i]);
    }
    int s2_size=s.size();
    if(s1_size==s2_size)
        return true;
    return false;

}

bool subsetCheckMap(int arr1[],int arr2[], int n, int m){
    if(m>n)
        return false;
    map<int,int> map1;
    for(int i=0;i<n;i++)
        map1[arr1[i]]++;
    for(int i=0;i<m;i++){
        if(map1.find(arr2[i])==map1.end())
            return false;
    }
    return true;
}

int main(){
    int arr1[] = {11, 1, 13, 21, 3, 7};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {11, 3, 7, 1};
    int m = sizeof(arr2)/sizeof(arr2[0]);
    bool result=subsetCheckSet(arr1,arr2,n,m);
    if(result)
        cout<<"Yes";
    else    
        cout<<"No";
    return 0;
}