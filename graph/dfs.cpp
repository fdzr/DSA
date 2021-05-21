#include <iostream>
#include "graph/graph1.h"

using namespace std;


int main(){
    Graph g;

    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);

    cout<<"DFS starting from vertex 2 \n";
    g.DFS(2);

    cout<<endl;

    Graph g1;
    g1.addEdge(0, 1);
    g1.addEdge(0, 9);
    g1.addEdge(1, 2);
    g1.addEdge(2, 0);
    g1.addEdge(2, 3);
    g1.addEdge(9, 3);

    g1.DFS1();
    
    return 0;
}
