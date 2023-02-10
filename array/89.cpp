#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
int oddCells(int m, int n, vector<vector<int>>& indices) {
    vector<vi> ans(m, vi(n));
    int countOdds = 0;

    for(auto coordinate: indices) {
        for(int i = 0; i < n; ++i) {
            ans[coordinate[0]][i]++;
            if(ans[coordinate[0]][i] % 2 == 0)
                countOdds--;
            else
                countOdds++;
        }
        for(int j = 0; j < m; ++j) {
            ans[j][coordinate[1]]++;
            if(ans[j][coordinate[1]] % 2 == 0)
                countOdds--;
            else
                countOdds++;
        }
    }

    return countOdds;
}


int main() {
    int m = 2, n = 2;
    vector<vi> indices = {{1,1},{0,0}};
    cout<<oddCells(m, n, indices);


    return 0;
}