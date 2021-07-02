#include<bits/stdc++.h>
using namespace std;
#define V 5

void addEdge(vector<int> graph[V], int u, int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

int cycle(vector<int> graph[V], int start){
    vector<bool> visited(V,false);
    stack <pair<int, int> > mystack;
    mystack.push(make_pair(start, -1));
    visited[start] = true;

    while (!mystack.empty())
    {
        int v = mystack.top().first;
        int f = mystack.top().second;
        mystack.pop();

        for (auto i=graph[v].begin();i!=graph[v].end();i++)
        {
            int w = *i;
            if (!visited[w])
            {
                mystack.push(make_pair(w, v));
                visited[w] = true;
            }
            else if (w != f)
                return true;
        }
    }
    return false;
}

int main(){
    vector<int> graph[V];
    addEdge(graph,0,1);
    addEdge(graph,1,2);
    addEdge(graph,2,3);
    addEdge(graph,4,3);
    addEdge(graph,1,4);
    int result=cycle(graph,0);
    if(result==1){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}