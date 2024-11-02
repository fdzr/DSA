#include <bits/stdc++.h>

// https://www.geeksforgeeks.org/minimum-time-required-so-that-all-oranges-become-rotten/

using namespace std;

using Graph = vector<vector<int>>;

struct sol
{
    pair<int, int> coordinates;
    int time;
};

void fillQueue(Graph &G, queue<sol> &q)
{
    for (int i = 0; i < G.size(); ++i)
    {
        for (int j = 0; j < G[i].size(); ++j)
        {
            if (G[i][j] == 2)
            {
                q.push(sol{{i, j}, 0});
            }
        }
    }
}

bool checkAnswer(Graph G)
{
    for (int i = 0; i < G.size(); ++i)
    {
        for (int j = 0; j < G[i].size(); ++j)
        {
            if (G[i][j] == 0)
                continue;
            if (G[i][j] != 2)
                return false;
        }
    }

    return true;
}

int solution(Graph &G)
{
    queue<sol> q;
    fillQueue(G, q);
    int lastTime;
    int pos;

    while (!q.empty())
    {
        sol s = q.front();
        q.pop();
        lastTime = s.time;

        // LEFT
        if (s.coordinates.second - 1 >= 0 && G[s.coordinates.first][s.coordinates.second - 1] == 1)
        {
            q.push(sol{{s.coordinates.first, s.coordinates.second - 1}, s.time + 1});
            G[s.coordinates.first][s.coordinates.second - 1] = 2;
        }
        // RIGHT
        if (s.coordinates.second + 1 < G[s.coordinates.first].size() && G[s.coordinates.first][s.coordinates.second + 1] == 1)
        {
            q.push(sol{{s.coordinates.first, s.coordinates.second + 1}, s.time + 1});
            G[s.coordinates.first][s.coordinates.second + 1] = 2;
        }
        // UP
        if (s.coordinates.first - 1 >= 0 && G[s.coordinates.first - 1][s.coordinates.second] == 1)
        {
            q.push(sol{{s.coordinates.first - 1, s.coordinates.second}, s.time + 1});
            G[s.coordinates.first - 1][s.coordinates.second] = 2;
        }
        // DOWN
        if (s.coordinates.first + 1 < G.size() && G[s.coordinates.first + 1][s.coordinates.second] == 1)
        {
            q.push(sol{{s.coordinates.first + 1, s.coordinates.second}, s.time + 1});
            G[s.coordinates.first + 1][s.coordinates.second] = 2;
        }
    }

    return checkAnswer(G) == true ? lastTime : -1;
}

int main()
{
    Graph G(3, vector<int>(5, 0));
    G[0] = {2, 1, 0, 2, 1};
    G[1] = {1, 0, 1, 2, 1};
    G[2] = {1, 0, 0, 2, 1};

    cout << solution(G);

    return 0;
}