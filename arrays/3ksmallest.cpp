#include<bits/stdc++.h>
using namespace std;

//easy solution O(nlogn)
int easySolve(int arr[],int n,int k){
    sort(arr,arr+n);
    return arr[k-1];
}

//using min heap O(n+klogn)

void swapfunc(int* x,int* y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

class MinHeap{
    int* harr;  //pointer to array of elements in heap
    int capacity; //max possible size of min heap
    int heap_size; //current no. of elements in min heap

public:
    MinHeap(int a[],int size); 
    void MinHeapify(int i); 
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return (2*i + 1);
    }
    int right(int i){
        return (2*i +2);
    }
    int extractMin();
    int getMin(){
        return harr[0];
    }
};

MinHeap::MinHeap(int a[],int size){
    heap_size=size;
    harr=a;
    int i=(heap_size-1)/2;
    while(i>=0){
        MinHeapify(i);
        i--;
    }
}

int MinHeap::extractMin(){
    if(heap_size==0)
        return INT_MAX;
    int root=harr[0];
    if(heap_size>1){
        harr[0]=harr[heap_size-1];
        MinHeapify(0);
    }
    heap_size--;
    return root;
}
void MinHeap::MinHeapify(int i){
    int l=left(i);
    int r=right(i);
    int smallest=i;
    if(l<heap_size && harr[l]<harr[i])
        smallest=l;
    if(r<heap_size && harr[r]<harr[smallest])
        smallest=r;
    if(smallest!=i){
        swapfunc(&harr[i],&harr[smallest]);
        MinHeapify(smallest);
    }
}

int minheapSolve(int arr[],int n,int k){
    MinHeap mh(arr,n);
    for(int i=0;i<k-1;i++)
        mh.extractMin();
    return mh.getMin();
}

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int result=minheapSolve(arr,n,k);
    cout<<result;
    return 0;
}