#include <bits/stdc++.h>
using namespace std;

struct Pair
{
    int min;
    int max;
};
//linear comparisons
struct Pair lSolve(int arr[], int n)
{
    struct Pair minmax;
    if (n == 1)
    {
        minmax.max = arr[0];
        minmax.min = arr[0];
        return minmax;
    }
    if (arr[0] > arr[1])
    {
        minmax.max = arr[0];
        minmax.min = arr[1];
    }
    else
    {
        minmax.max = arr[1];
        minmax.min = arr[0];
    }
    for (int i = 2; i < n; i++)
    {
        if (arr[i] > minmax.max)
            minmax.max = arr[i];
        else if (arr[i] < minmax.min)
            minmax.min = arr[i];
    }
    return minmax;
}
//recursive approach
struct Pair rSolve(int arr[], int low, int high)
{
    struct Pair minmax, left, right;
    if (low == high)
    {
        minmax.max = arr[low];
        minmax.min = arr[low];
        return minmax;
    }
    if (high == low + 1)
    {
        if (arr[low] > arr[low + 1])
        {
            minmax.max = arr[low];
            minmax.min = arr[low + 1];
        }
        else
        {
            minmax.max = arr[low + 1];
            minmax.min = arr[low];
        }
        return minmax;
    }
    int mid = (low + high) / 2;
    left = rSolve(arr, low, mid);
    right = rSolve(arr, mid + 1, high);

    if (left.min < right.min)
        minmax.min = left.min;
    else
        minmax.min = right.min;
    if (left.max > right.max)
        minmax.max = left.max;
    else
        minmax.max = right.max;
    return minmax;
}
//compair in pairs
struct Pair pSolve(int arr[], int n){
    struct Pair minmax;
    if(n%2==0){
        if(arr[0]>arr[1]){
            minmax.max=arr[0];
            minmax.min=arr[1];
        }
        else{
            minmax.min=arr[0];
            minmax.max=arr[1];
        }
    }
    else{
        minmax.min=arr[0];
        minmax.max=arr[0];
    }
    int i=2;
    while(i<n-1){
        if(arr[i]>arr[i+1]){
            if(arr[i]>minmax.max)
                minmax.max=arr[i];
            if(arr[i+1]<minmax.min)
                minmax.min=arr[i+1];
        }
        else{
            if(arr[i+1]>minmax.max)
                minmax.max=arr[i+1];
            if(arr[i]<minmax.min)
                minmax.min=arr[i];
        }
        i+=2;
    }
    return minmax;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element: ";
        cin >> arr[i];
    }
    struct Pair result = pSolve(arr, n);
    cout << result.max << endl;
    cout << result.min << endl;
    return 0;
}