#include <bits/stdc++.h>
using namespace std;
#define V 5

void addEdge(vector < pair<int, int> > graph[V], int u, int v, int weight)
{
    graph[u].push_back(make_pair(v, weight));
}

int main()
{
    vector<pair<int,int> > graph[V];
    addEdge(graph, 0, 1, 1);
    addEdge(graph, 0, 4, 5);
    addEdge(graph, 1, 1, 2);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 4);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 3, 2, 2);
    addEdge(graph, 3, 4, 3);
    for (int i = 0; i < V; i++)
    {
        cout << i;
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << "->" << graph[i][j].first << "," << graph[i][j].second;
        }
        cout << endl;
    }
    return 0;
}