#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
int minPathSum(vector<vector<int>> &grid)
{
    int sum = 0;
    for (int i = 0; i < grid[0].size(); ++i)
    {
        sum += grid[0][i];
        grid[0][i] = sum;
    }

    for (int i = 1; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[i].size(); ++j)
        {
            if (j == 0)
            {
                grid[i][j] = grid[i][j] + grid[i-1][j];
            }
            else
            {
                grid[i][j] = min(grid[i][j] + grid[i - 1][j], grid[i][j] + grid[i][j - 1]);
            }
        }
    }

    return grid[grid.size() - 1][grid[0].size() - 1];
}

int main()
{
    vvi grid = {{1, 2, 3}, {4, 5, 6}};
    cout<<minPathSum(grid);

    return 0;
}