#include<bits/stdc++.h>
using namespace std;

int solvebrute(int arr[],int n){
    int count=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
                count++;
            }
        }
    }
    return count;
}

int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i=left, j=mid, k=left;
    int count = 0;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            count = count + (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
    return count;
}

int mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, count = 0;
    if (right > left) {
        mid = (right + left) / 2;
        count += mergeSort(arr, temp, left, mid);
        count += mergeSort(arr, temp, mid + 1, right);
        count += merge(arr, temp, left, mid + 1, right);
    }
    return count;
}


int main(){
    int arr[] = {10, 10, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int temp[n];
    int result=mergeSort(arr,temp,0,n-1);
    cout<<result;
    return 0;
}