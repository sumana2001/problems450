#include<bits/stdc++.h>
using namespace std;
#define V 7

void addEdge(vector<int> graph[V],int u, int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void bfs(vector<int> graph[V], int start){
    vector<bool> visited(V,false);
    queue<int> q;
    q.push(start);
    visited[start]=true;
    while(!q.empty()){
        int v=q.front();
        cout<<v<<" ";
        q.pop();
        for(auto i=graph[v].begin();i!=graph[v].end();i++){
            if(!visited[*i]){
                q.push(*i);
                visited[*i]=true;
            }
        }
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
    bfs(graph,0);
    return 0;
}