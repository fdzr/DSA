#include <bits/stdc++.h>

using namespace std;

int countNegatives(vector<vector<int>>& grid) {
    int cont = 0;
    for(auto row: grid) {
        cont += count_if(row.begin(), row.end(), [](int elem) {
            return elem < 0;
        });
    }
    return cont;
}

using vvi = vector<vector<int>>;

int main() {
    vvi grid = {{4,3,2,-0},
                {3,2,1,10},
                {1,1,11,2},
                {1,1,2,3}};
    cout<<countNegatives(grid);

    return 0;
}