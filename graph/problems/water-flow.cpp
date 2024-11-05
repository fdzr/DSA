// https://www.geeksforgeeks.org/atlantic-pacific-water-flow/

#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;
using Matrix = Graph;

vector<int> directionRows = {-1, 0, 0, 1};
vector<int> directionCols = {0, -1, 1, 0};

bool isValid(const Graph &G, const Matrix &visited, int row, int col)
{
    return row < G.size() && row >= 0 && col >= 0 && col < G[0].size() && visited[row][col] == 0;
}

void BFS(const Graph &G, Matrix &visited, queue<pair<int, int>> &q)
{

    while (!q.empty())
    {
        auto coordinates = q.front();
        q.pop();
        visited[coordinates.first][coordinates.second] = 1;

        for (int i = 0; i < directionRows.size(); ++i)
        {
            int newRow = coordinates.first + directionRows[i];
            int newCol = coordinates.second + directionCols[i];

            if (isValid(G, visited, newRow, newCol) && G[coordinates.first][coordinates.second] <= G[newRow][newCol])
            {
                q.push(pair<int, int>(newRow, newCol));
                visited[newRow][newCol] = 1;
            }
        }
    }
}

void DFS(const Graph &G, Matrix &visited, int row, int col)
{
    visited[row][col] = 1;

    for (int i = 0; i < directionRows.size(); ++i)
    {
        int newRow = row + directionRows[i];
        int newCol = col + directionCols[i];

        if (isValid(G, visited, newRow, newCol) && G[row][col] <= G[newRow][newCol])
        {
            DFS(G, visited, newRow, newCol);
        }
    }
}

int BFSDisconnected(const Graph &G)
{
    Matrix visitedP(G.size(), vector<int>(G[0].size(), 0));
    Matrix visitedA(G.size(), vector<int>(G[0].size(), 0));

    queue<pair<int, int>> qa, qp;

    for (int i = 0; i < G[0].size(); ++i)
    {
        qp.push(pair<int, int>(0, i));
        qa.push(pair<int, int>(G.size() - 1, i));
    }

    for (int j = 0; j < G.size(); ++j)
    {
        qp.push(pair<int, int>(j, 0));
        qa.push(pair<int, int>(j, G[0].size() - 1));
    }

    BFS(G, visitedP, qp);
    BFS(G, visitedA, qa);

    int answer = 0;

    for (int i = 0; i < G.size(); ++i)
    {
        for (int j = 0; j < G[0].size(); ++j)
        {
            if (visitedA[i][j] == visitedP[i][j])
                ++answer;
        }
    }

    return answer;
}

int DFSDisconnected(Graph &G)
{
    Matrix visitedP(G.size(), vector<int>(G[0].size(), 0));
    Matrix visitedA(G.size(), vector<int>(G[0].size(), 0));

    for (int i = 0; i < G[0].size(); ++i)
    {
        DFS(G, visitedP, 0, i);
        DFS(G, visitedA, G.size() - 1, i);
    }

    for (int j = 0; j < G.size(); ++j)
    {
        DFS(G, visitedP, j, 0);
        DFS(G, visitedA, j, G[0].size() - 1);
    }

    int answer = 0;
    for (int i = 0; i < G.size(); ++i)
    {
        for (int j = 0; j < G[0].size(); ++j)
        {
            if (visitedA[i][j] == visitedP[i][j])
                ++answer;
        }
    }

    return answer;
}

int main()
{
    Graph G(5, vector<int>(5, 0));
    
    G[0] = {1, 2, 2, 3, 5};
    G[1] = {3, 2, 3, 4, 4};
    G[2] = {2, 4, 5, 3, 1};
    G[3] = {6, 7, 1, 4, 5};
    G[4] = {5, 1, 1, 2, 4};

    printf("%d\n", BFSDisconnected(G));
    printf("%d\n", DFSDisconnected(G));

    printf("\n");

    G.clear();
    G.resize(2);

    G[0] = {2, 2};
    G[1] = {2, 2};

    printf("%d\n", BFSDisconnected(G));
    printf("%d\n", DFSDisconnected(G));



    return 0;
}