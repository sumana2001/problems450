#include<bits/stdc++.h>
using namespace std;
#define V 5

void addEdge(vector<int> graph[V],int u, int v){
    graph[u].push_back(v);
}

vector<int> kahn(vector<int> graph[V]){
    vector<int> result;
    queue<int> q;
    vector<int> indegree(V,0);
    for(int i=0;i<V;i++){
        for(int j=0;j<graph[i].size();j++){
            indegree[graph[i][j]]++;
        }
    }
    for(int i=0;i<indegree.size();i++){
        if(indegree[i]==0)
            q.push(indegree[i]);
    }
    while(!q.empty()){
        int v=q.front();
        q.pop();
        result.push_back(v);
        for(auto i=graph[v].begin();i!=graph[v].end();i++){
            indegree[*i]--;
            if(indegree[*i]==0)
                q.push(*i);
        }
    }
    return result;
}

int main(){
    vector<int> graph[V];
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,2);
    addEdge(graph,1,3);
    addEdge(graph,2,3);
    addEdge(graph,2,4);
    vector<int> result=kahn(graph);
    if(result.size()==V){
        for(int i=0;i<V;i++){
            cout<<result[i]<<" ";
        }
    }
    else{
        cout<<"Topological sort not possible!";
    }
    return 0;
}