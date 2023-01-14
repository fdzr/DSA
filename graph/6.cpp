#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using um = unordered_map<int, vi>;

void loadGraph(vvi edges, um &graph) {
    for(int i = 0; i < edges.size(); ++i)
        graph[i] = edges[i];
}

void DFS(um graph, int v, vector<bool> &visited, set<int> &conj) {
    visited[v] =true;
    conj.insert(v);

    for(auto vertex: graph[v]) {
        if(!visited[vertex]) {
            visited[vertex] = true;
            DFS(graph, vertex, visited, conj);
        }
    }

}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    um graph;
    set<int> conj;
    loadGraph(rooms, graph);
    vector<bool> visited(graph.size());

    DFS(graph, 0, visited, conj);
    
    return graph.size() == conj.size();

}

int main() {
    vvi rooms = {{1,3},{3,0,1},{2},{}};
    cout<<canVisitAllRooms(rooms);

    return 0;
}