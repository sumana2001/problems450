#include<bits/stdc++.h>
using namespace std;
#define V 5

void addEdge(vector<int> graph[V], int u, int v){
    graph[u].push_back(v);
}

void dfs(vector<int> graph[V], vector<bool>& visited, int start){
    cout<<start<<" ";
    visited[start]=true;
    int v=start;
    for(auto i=graph[v].begin();i!=graph[v].end();i++){
        if(!visited[*i]){
            dfs(graph,visited,*i);
        }
    }
}

int main(){ 
    vector<int> graph[V];
    addEdge(graph,0,4);
    addEdge(graph,0,2);
    addEdge(graph,0,3);
    addEdge(graph,2,1);
    vector<bool> visited(V,false);
    dfs(graph,visited,0);
    return 0;
}