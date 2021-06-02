#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;


class Graph{
    int V;
    list<int> *adj;

    public:
        Graph(int V): V{V}, adj{new list<int>[V]}{}

        void DFSUtil(int s, vector<bool> &visited){
            stack<int> st;
            st.push(s);

            while(!st.empty()){
                s = st.top();
                st.pop();

                if(!visited[s]){
                    cout<<s<<" ";
                    visited[s] = true;
                }

                for(auto i=adj[s].begin(); i!=adj[s].end(); ++i)
                    if(!visited[*i])
                        st.push(*i);
            }
        }

        void DFS1(){
            vector<bool> visited(V, false);

            for(int i=0;i<V; ++i)
                if(!visited[i])
                    DFSUtil(i, visited);
        }

        void DFS(int s){
            vector<bool> visited(V, false);
            stack<int> st;
            
            st.push(s);

            while(!st.empty()){
                s = st.top();
                st.pop();

                if(!visited[s]){
                    cout<<s<<" ";    
                    visited[s] = true;
                }

                for(auto i=adj[s].begin();i!=adj[s].end(); ++i)
                    if(!visited[*i])
                        st.push(*i);
            }
        }

        void addEdge(int v, int w){
            adj[v].push_back(w);
        }
};



int main(){
    Graph g(5); // Total 5 vertices in graph
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 4);
 
    cout << "Following is Depth First Traversal\n";
    g.DFS(0);
    cout<<endl;

    g.DFS1();
    
    return 0;
}
