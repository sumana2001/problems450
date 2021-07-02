#include<bits/stdc++.h>
using namespace std;
#define V 4

void addEdge(vector<int> graph[V], int u, int v){
    graph[u].push_back(v);
}

int cycle(vector<int> graph[V], int start){
    vector<bool> visited(V,false);
    stack<int> s;
    s.push(start);
    visited[start]=true;
    while(!s.empty()){
        int v=s.top();
        s.pop();
        for(auto i=graph[v].begin();i!=graph[v].end();i++){
            if(visited[*i]){
                return 1;
            }
            else{
                visited[*i]=true;
                s.push(*i);
            }
        }
    }
    return 0;
}

int main(){
    vector<int> graph[V];
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,2);
    addEdge(graph,2,0);
    addEdge(graph,2,3);
    addEdge(graph,3,3);
    int result=cycle(graph,0);
    if(result==1){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}