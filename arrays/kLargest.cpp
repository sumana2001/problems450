#include<bits/stdc++.h>
using namespace std;

void solve1(int arr[],int n,int k){
    sort(arr,arr+n);
    for(int i=n-1;i>n-1-k;i--){
        cout<<arr[i]<<" ";
    }
}

class MinHeap{
    int size;
    int *arr;
public:
    MinHeap(int size, int input[]){
        this->size=size;
        this->arr=input;
        buildHeap();
    }
    void heapify(int i){
        if(i>=size/2)
            return;
        int smallest;
        int left=2*i+1;
        int right=2*i+2;
        smallest=arr[left]<arr[i]?left:i;
        if(right<size)
            smallest=arr[right]<arr[smallest]?right:smallest;
        if(smallest!=i){
            swap(arr[i],arr[smallest]);
            heapify(smallest);
        }
    }
    void buildHeap(){
        for(int i=size/2-1;i>=0;i--){
            heapify(i);
        }
    }
};

void solve2(int arr[],int n,int k){
    MinHeap* m=new MinHeap(k,arr);
    for(int i=k;i<n;i++){
        if(arr[0]>arr[i])
            continue;
        else{
            arr[0]=arr[i];
            m->heapify(0);
        }
    }
    for(int i=0;i<k;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[]={1,23,12,9,30,2,50};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    solve1(arr,n,k);
    cout<<endl;
    solve2(arr,n,k);
    return 0;
}