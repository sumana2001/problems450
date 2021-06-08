#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int l,int r,int key){
    if(r>=l){
        int mid=(l+r)/2;
        if(key==arr[mid])
            return mid;
        if(key<arr[mid])
            return binarySearch(arr,l,mid-1,key);
        return binarySearch(arr,mid+1,r,key);
    }
    return -1;
}

//using set
void findUnion(int arr1[], int arr2[], int n, int m)
{
    set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(arr1[i]);
    for (int i = 0; i < m; i++)
        s.insert(arr2[i]);
    for (auto itr = s.begin(); itr != s.end(); itr++)
        cout << *itr << " ";
}

void findIntersection(int arr1[], int arr2[], int n, int m)
{
    set<int> s1, s2;
    for (int i = 0; i < n; i++)
        s1.insert(arr1[i]);
    for (int i = 0; i < m; i++)
        s2.insert(arr2[i]);
    for (auto itr = s1.begin(); itr != s1.end(); itr++)
    {
        if (s2.find(*itr) != s2.end())
            cout << *itr << " ";
    }
}

//without set
void findUnion2(int arr1[], int arr2[], int n, int m){
    if(n>m){
        int* tempp=arr1;
        arr1=arr2;
        arr2=tempp;

        int temp=n;
        n=m;
        m=temp;
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
    for(int i=0;i<n;i++)
        cout<<arr1[i]<<" ";
    for(int i=0;i<m;i++){
        if(binarySearch(arr1,0,m-1,arr2[i])==-1)
            cout<<arr2[i]<<" ";
    }
}

void findIntersection2(int arr1[], int arr2[], int n, int m){
    if(n>m){
        int* tempp=arr1;
        arr1=arr2;
        arr2=tempp;

        int temp=n;
        n=m;
        m=temp;
    }
    sort(arr1,arr1+n);
    for(int i=0;i<m;i++){
        if(binarySearch(arr1,0,m-1,arr2[i])!=-1)
            cout<<arr2[i]<<" ";
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int arr1[n], arr2[m];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter number in 1st array: ";
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cout << "Enter number in 2nd array: ";
        cin >> arr2[i];
    }
    findUnion2(arr1, arr2, n, m);
    cout << endl;
    findIntersection2(arr1, arr2, n, m);
    return 0;
}