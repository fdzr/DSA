#include <bits/stdc++.h>

using namespace std;
const int MAX = 100001;

bool visit[MAX] = {0};
int intime[MAX];
int outime[MAX];
int timer = 0;


void DFS(vector<int> graph[], int v){
	visit[v] = true;
	++timer;
	
	intime[v] = timer;
	
	auto it = graph[v].begin();

	while(it != graph[v].end()){
		if(visit[*it] == false)
			DFS(graph, *it);
	
		++it;		
	}
	
	++timer;
	outime[v] = timer;
}


bool query(int u, int v){
	return (
		(intime[u] < intime[v] && outime[u] > outime[v]) ||
		(intime[v] < intime[u] && outime[v] > outime[u])
	);
}


int main(){
	int n = 9;
	vector<int> graph[n + 1];

	graph[1].push_back(2);
    graph[1].push_back(3);
    graph[3].push_back(6);
    graph[2].push_back(4);
    graph[2].push_back(5);
    graph[5].push_back(7);
    graph[5].push_back(8);
    graph[5].push_back(9);
	
	
	DFS(graph, 1);
	
	query(1, 5)? cout << "Yes\n" : cout << "No\n";
    query(2, 9)? cout << "Yes\n" : cout << "No\n";
    query(2, 6)? cout << "Yes\n" : cout << "No\n";

	return 0;
}
