#include<bits/stdc++.h>
using namespace std;
#define V 7

void addEdge(vector<int> graph[V], int u, int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void dfs_i(vector<int> graph[V], int start){
    vector<bool> visited(V,false);
    stack<int> s;
    s.push(start);
    visited[start]=true;
    while(!s.empty()){
        int v=s.top();
        cout<<v<<" ";
        s.pop();
        for(auto i=graph[v].begin();i!=graph[v].end();i++){
            if(!visited[*i]){
                s.push(*i);
                visited[*i]=true;
            }
        }
    }
}

void dfs_r(vector<int> graph[V], vector<bool>& visited, int start){
    cout<<start<<" ";
    visited[start]=true;
    int v=start;
    for(auto i=graph[v].begin();i!=graph[v].end();i++){
        if(!visited[*i])
            dfs_r(graph,visited,*i);
    }
}

int main(){
    vector<int> graph[V];
    addEdge(graph,0,1);
    addEdge(graph,0,3);
    addEdge(graph,1,2);
    addEdge(graph,2,3);
    addEdge(graph,2,6);
    addEdge(graph,3,4);
    addEdge(graph,4,5);
    addEdge(graph,5,6);
    dfs_i(graph,0);
    cout<<endl;
    vector<bool> visited(V,false);
    dfs_r(graph,visited,0);
    return 0;
}