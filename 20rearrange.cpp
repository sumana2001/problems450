#include<bits/stdc++.h>
using namespace std;

void rearrange(int arr[], int n){
    int negative=0, positive=1, i=0;
    while(i<n)
    {
        if(arr[i] < 0 && negative <n)
        {
            swap(arr[i], arr[negative]);
            negative+=2;
        }
        i++;
    }
    i=0;
    while(i<n)
    {
        if(arr[i] >= 0 && positive <n)
        {
            swap(arr[i], arr[positive]);
            positive+=2;
        }
        i++;
    }
}

int main(){
    int arr[] = {-2, 3, 4, -1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Given array is \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    rearrange(arr, n);
    cout << "\nRearranged array is \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}