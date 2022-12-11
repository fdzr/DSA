#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
    vector<vector<int>> ans;
    vector<int> tmp;
    for(int i = 0; i < grid.size() - 2; ++i) {
        for(int j = 0; j < grid[i].size() - 2; ++j) {
            int max_1 = *max_element(grid[i].begin() + j, grid[i].begin() + j + 3);
            int max_2 = *max_element(grid[i + 1].begin() + j, grid[i + 1].begin() + j + 3);
            int max_3 = *max_element(grid[i + 2].begin() + j, grid[i + 2].begin() + j + 3);
            int max_ = max(max_1, max(max_2, max_3));
            tmp.push_back(max_);
        }
        ans.push_back(tmp);
        tmp.clear();
    }

    return ans;
}


int main() {
    vector<vector<int>> grid = {{9,9,8,1},
                                {5,6,2,6},
                                {8,2,6,4},
                                {6,2,2,2},
                                };
    vector<vector<int>> ans = largestLocal(grid);

    for(auto v: ans) {
        for(auto e: v){
            cout<<e<<" ";
        }
        cout<<endl;
    }

    return 0;
}