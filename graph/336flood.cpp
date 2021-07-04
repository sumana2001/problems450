#include<bits/stdc++.h>
using namespace std;
#define MAX 3

void dfs(int m[][MAX],int i, int j, int newColor, int ele){
    if(i<0 || i>=MAX || j<0 || j>=MAX)
        return;
    if(m[i][j]!=ele)
        return;
    m[i][j]=newColor;
    dfs(m,i+1,j,newColor,ele);
    dfs(m,i,j-1,newColor,ele);
    dfs(m,i-1,j,newColor,ele);
    dfs(m,i,j+1,newColor,ele);
}

void flood(int m[][MAX], int sr, int sc, int newColor){
    int ele=m[sr][sc];
    dfs(m,sr,sc,newColor,ele);
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            cout<<m[i][j];
        }
        cout<<endl;
    }
}

int main(){
    int m[MAX][MAX]={{1,1,1},{1,1,0},{1,0,1}};
    int sr=1,sc=1,newColor=2;
    flood(m,sr,sc,newColor);
    return 0;
}