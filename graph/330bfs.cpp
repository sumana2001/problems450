#include<bits/stdc++.h>
using namespace std;
#define V 5

void addEdge(vector<int> graph[V],int u, int v){
    graph[u].push_back(v);
}

void bfs(vector<int> graph[V], int start){
    queue<int> q;
    vector<bool> visited(V,false);
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
    addEdge(graph,0,4);
    addEdge(graph,0,2);
    addEdge(graph,0,3);
    addEdge(graph,2,1);
    bfs(graph,0);
    return 0;
}