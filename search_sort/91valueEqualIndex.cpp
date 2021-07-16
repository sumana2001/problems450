#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={15, 2, 45, 12, 7};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int> result;
    for(int i=0;i<n;i++){
        if(arr[i]==i+1){
            result.push_back(arr[i]);
        }
    }
    if(result.size()==0){
        cout<<"No such element"<<endl;
        return 0;
    }
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
    return 0;
}