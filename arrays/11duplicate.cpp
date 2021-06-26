#include<bits/stdc++.h>
using namespace std;

int duplicate(int arr[],int n){
    sort(arr,arr+n);
    for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1])
            return arr[i];
    }
    return -1;
}
int setduplicate(int n){
    set<int> s;
    for(int i=0;i<n;i++){
        int x;
        cout<<"Enter number: ";
        cin>>x;
        if(s.find(x)!=s.end())
            return x;
        s.insert(x);
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++){
    //     cout<<"Enter number: ";
    //     cin>>arr[i];
    // }
    int result=setduplicate(n);
    cout<<result;
    return 0;
}