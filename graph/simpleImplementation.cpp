#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}


void printGraph(vector<int> adj[], int v){
    for(int i=0;i<v; ++i){
        cout<<"\n Adjacency list of vertex "<<i<<"\n head ";
        for(auto a: adj[i])
            cout<<"-> "<<a;
        printf("\n");
    }
}


int main(){
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, V);

    return 0;
}
