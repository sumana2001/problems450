#include <bits/stdc++.h>
using namespace std;
#define V 5
#define E 8

void addEdge(int mat[V][E], int u, int v, int e)
{
    mat[u][e]=1;
    if(u!=v)
        mat[v][e]=-1;
}

int main()
{
    int mat[V][E] = {0};
    addEdge(mat, 0, 1, 0);
    addEdge(mat, 0, 4, 1);
    addEdge(mat, 1, 4, 2);
    addEdge(mat, 1, 3, 3);
    addEdge(mat, 1, 1, 5);
    addEdge(mat, 1, 2, 6);
    addEdge(mat, 3, 4, 4);
    addEdge(mat, 3, 2, 7);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < E; j++)
        {
            cout << mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}