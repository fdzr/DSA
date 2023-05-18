//
// Created by fzamora on 18-05-23.
//
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi= vector<vi>;
vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
    vvi diff;
    vi onesAndZerosRow(grid.size());
    vi onesAndZerosColumn(grid[0].size());
    int contOnesRows = 0;
    int contZerosRows = 0;
    int contOnesColumns = 0;
    int contZerosColumns = 0;

    for(int i = 0; i < grid.size(); ++i) {
        for(int j = 0; j < grid[i].size(); ++j) {
            if(grid[i][j] == 0)
                contZerosRows++;
            if(grid[i][j] == 1)
                contOnesRows++;
        }
        onesAndZerosRow[i] = contOnesRows - contZerosRows;
        contOnesRows = 0;
        contZerosRows = 0;
    }

    for(int i = 0; i < grid[0].size(); ++i) {
        for(int j = 0; j < grid.size(); ++j) {
            if(grid[j][i] == 0)
                contZerosColumns++;
            if(grid[j][i] == 1)
                contOnesColumns++;
        }
        onesAndZerosColumn[i] = contOnesColumns - contZerosColumns;
        contOnesColumns = 0;
        contZerosColumns = 0;
    }

    for(int i =0;i < grid.size(); ++i) {
        vi columns(grid[i].size());
        for(int j =0;j < grid[i].size(); ++j) {
            columns[j] = (onesAndZerosRow[i] + onesAndZerosColumn[j]);
        }
        diff.push_back(columns);
    }

    return diff;
}

int main() {
    vvi grid = {{1,1,1}, {1,1,1}};
    vvi ans = onesMinusZeros(grid);
    for(auto rows: ans) {
        for(auto elem: rows)
            cout<<elem<<" ";
        cout<<endl;
    }

    return 0;
}