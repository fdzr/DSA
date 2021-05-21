#include <iostream>
#include "graph/graph.h"

using namespace std;


int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout<<"BFS is starting from vertex 2 \n";
    g.BFS(2);

    return 0;
}

