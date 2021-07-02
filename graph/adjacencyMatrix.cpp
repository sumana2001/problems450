#include<bits/stdc++.h>
using namespace std;
#define V 5

void addEdge(int mat[][V],int u, int v){
    mat[u][v]=1;
}

int main(){
    int mat[V][V]={0};
    addEdge(mat,0,1);
    addEdge(mat,0,4);
    addEdge(mat,1,1);
    addEdge(mat,1,2);
    addEdge(mat,1,3);
    addEdge(mat,1,4);
    addEdge(mat,3,2);
    addEdge(mat,3,4);
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}