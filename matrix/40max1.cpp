#include<bits/stdc++.h>
using namespace std;
#define r 4
#define c 4

int bsearch(bool arr[], int low, int high){
    if(high>=low){
        int mid=low+(high-low)/2;
        if(mid==0 || arr[mid]==1 && arr[mid-1]==0)
            return mid;
        if(arr[mid]==0)
            return bsearch(arr,mid+1,high);
        else
            return bsearch(arr,low,mid-1);
    }
    return -1;
}

int max1(bool arr[r][c]){
    int max_index=0,max=-1;
    for(int i=0;i<r;i++){
        int index=bsearch(arr[i],0,c-1);
        if(index!=-1 && c-index>max){
            max=c-index;
            max_index=i;
        }
    }
    return max_index;
}

//Method2
int max1Method2(bool arr[r][c])
{
    int j,max_row_index = 0;
    j = c - 1;

    for (int i = 0; i < r; i++) {
      bool flag=false;
        while (j >= 0 && arr[i][j] == 1) {
            j = j - 1; 
          flag=true ;
          }
      if(flag){
            max_row_index = i; 
        }
    }
      if(max_row_index==0)
            return -1;
    return max_row_index;
}

int main(){
    bool arr[r][c] = { {0, 0, 0, 1},
                    {0, 1, 1, 1},
                    {1, 1, 1, 1},
                    {0, 0, 0, 0}};
    cout<<max1Method2(arr)<<endl;
    return 0;
}