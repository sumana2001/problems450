#include<bits/stdc++.h>
using namespace std;
#define V 5

void addEdge(vector<int> graph[V],int u, int v){
    graph[u].push_back(v);
}

void dfs(vector<int> graph[V], vector<bool>& visited, vector<int>& result, int node){
    visited[node]=true;
    int v=node;
    for(auto i=graph[v].begin();i!=graph[v].end();i++){
        if(!visited[*i]){
            dfs(graph,visited,result,*i);
        }
    }
    result.push_back(node);
}

int main(){
    vector<int> graph[V];
    vector<bool> visited(V,false);
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,2);
    addEdge(graph,1,3);
    addEdge(graph,2,3);
    addEdge(graph,2,4);
    vector<int> result;
    dfs(graph,visited,result,0);
    if(result.size()==V){
        for(int i=V-1;i>=0;i--){
            cout<<result[i]<<" ";
        }
    }
    else{
        cout<<"Topological sort not possible!";
    }
    return 0;
}