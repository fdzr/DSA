// https://www.geeksforgeeks.org/shortest-path-in-a-binary-maze/

#include <bits/stdc++.h>

using namespace std;

using Matrix = vector<vector<int>>;

vector<int> positionRows = {-1, 0, 0, 1};
vector<int> positionCols = {0, -1, 1, 0};

bool isValid(const Matrix &M, const Matrix &visited, int row, int col)
{
    return row >= 0 && row < M.size() && col >= 0 && col < M[0].size() && visited[row][col] == 0 && M[row][col] == 1;
}

void DFS(Matrix &M, pair<int, int> origin, pair<int, int> dest, Matrix &visited, int cont, int &minDistance)
{
    visited[origin.first][origin.second] = 1;
    if (origin.first == dest.first && origin.second == dest.second)
    {
        minDistance = min(minDistance, cont);
        return;
    }

    for (int i = 0; i < positionRows.size(); ++i)
    {
        int newRow = origin.first + positionRows[i];
        int newCol = origin.second + positionCols[i];

        if (isValid(M, visited, newRow, newCol))
        {
            DFS(M, pair<int, int>(newRow, newCol), dest, visited, cont + 1, minDistance);
        }
    }

    visited[origin.first][origin.second] = 0;
}

int solution(Matrix &M, pair<int, int> origin, pair<int, int> dest)
{
    int minDistance = INT_MAX;
    Matrix visited(M.size(), vector<int>(M[0].size(), 0));
    DFS(M, origin, dest, visited, 0, minDistance);

    return minDistance;
}

int main()
{
    Matrix M(9, vector<int>(9, 0));
    M[0] = {1, 0, 1, 1, 1, 1, 0, 1, 1, 1};
    M[1] = {1, 0, 1, 0, 1, 1, 1, 0, 1, 1};
    M[2] = {1, 1, 1, 0, 1, 1, 0, 1, 0, 1};
    M[3] = {0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
    M[4] = {1, 1, 1, 0, 1, 1, 1, 0, 1, 0};
    M[5] = {1, 0, 1, 1, 1, 1, 0, 1, 0, 0};
    M[6] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 1};
    M[7] = {1, 0, 1, 1, 1, 1, 0, 1, 1, 1};
    M[8] = {1, 1, 0, 0, 0, 0, 1, 0, 0, 1};

    printf("%d\n", solution(M, {0, 0}, {3, 4}));

    return 0;
}