#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
    for(auto &row: image) {
        reverse(row.begin(), row. end());
        transform(row.begin(), row.end(), row.begin(), [](int elem) {
            return !(elem == 1);
        });

    }
    return image;
}


int main() {
    vector<vector<int>> grid = {{1,1,0,0},
                                {1,0,0,1},
                                {0,1,1,1},
                                {1,0,1,0}};

    flipAndInvertImage(grid);
    for(auto row: grid) {
        for(auto e: row)
            cout<<e<<" ";
        cout<<endl;
    }
     


    return 0;
}