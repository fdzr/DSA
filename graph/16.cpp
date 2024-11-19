#include <bits/stdc++.h>

using namespace std;

using Grid = vector<vector<char>>;
using Matrix = vector<vector<int>>;

vector<int> posRows = {-1, 0, 0, 1};
vector<int> posCols = {0, -1, 1, 0};

bool isEdge(const Grid &G, int row, int col)
{
    return col == 0 || col == G[0].size() - 1 || row == 0 || row == G.size() - 1;
}

bool isValid(const Grid &G, int row, int col)
{
    return row >= 0 && row < G.size() && col >= 0 && col < G[0].size() && G[row][col] == 'O';
}

void DFS(Grid &G, int row, int col)
{
    G[row][col] = '#';

    for (int i = 0; i < posRows.size(); ++i)
    {
        int newPosRow = row + posRows[i];
        int newPosCol = col + posCols[i];

        if (isValid(G, newPosRow, newPosCol) && isEdge(G, newPosRow, newPosCol) == false)
        {
            G[newPosRow][newPosCol] = 'X';
            DFS(G, newPosRow, newPosCol);
        }
    }
}

void solve(Grid &G)
{
    for (int col = 0; col < G[0].size(); ++col)
    {
        if (G[0][col] == 'O')
            DFS(G, 0, col);
        if (G[G.size() - 1][col] == 'O')
            DFS(G, G.size() - 1, col);
    }

    for (int row = 0; row < G.size(); ++row)
    {
        if (G[row][0] == 'O')
            DFS(G, row, 0);
        if (G[row][G[0].size() - 1] == 'O')
            DFS(G, row, G[0].size() - 1);
    }

    for (int i = 0; i < G.size(); ++i)
    {
        for (int j = 0; j < G[i].size(); ++j)
        {
            if(G[i][j] == 'O')
                G[i][j] = 'X';
            if(G[i][j] == '#')
                G[i][j] = 'O';
        }
    }
}

void printMatrix(const Grid &G)
{
    for (int i = 0; i < G.size(); ++i)
    {
        for (int j = 0; j < G[i].size(); ++j)
            cout << G[i][j] << " ";

        cout << "\n";
    }
}

int main()
{

    Grid G(4);
    G[0] = {'X', 'X', 'X', 'X'};
    G[1] = {'X', 'O', 'O', 'O'};
    G[2] = {'X', 'X', 'O', 'X'};
    G[3] = {'X', 'O', 'X', 'X'};

    printMatrix(G);
    cout << "\n";
    solve(G);
    printMatrix(G);

    return 0;
}