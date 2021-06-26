#include<bits/stdc++.h>
using namespace std;

struct Interval{
    int s,e;
};

bool compare(Interval a, Interval b){
    return a.s<b.s;
}

void merge(Interval arr[], int n){
    sort(arr,arr+n,compare);
    int index=0;
    for(int i=1;i<n;i++){
        if(arr[index].e>=arr[i].s){
            arr[index].e=max(arr[index].e,arr[i].e);
            arr[index].s=min(arr[index].s,arr[i].s);
        }
        else{
            index++;
            arr[index]=arr[i];
        }
    }
    cout<<"The merged intervals are: "<<endl;
    for(int i=0;i<=index;i++)
        cout<<"["<<arr[i].s<<","<<arr[i].e<<"] ";
}

int main()
{
    Interval arr[] = {{1,3},{2,6},{8,10},{15,18}};
    int n = sizeof(arr)/sizeof(arr[0]);
    merge(arr, n);
    return 0;
}