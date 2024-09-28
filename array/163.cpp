#include <bits/stdc++.h>

using namespace std;


void rotate(vector<vector<int>>& matrix) {
    for(int row = 0; row < matrix.size(); ++row) {
        for(int col = row + 1; col < matrix[row].size(); ++col) {
            swap(matrix[row][col], matrix[col][row]);
        }
    }

    for(int i = 0; i < matrix.size(); ++i) {
        int n = matrix[i].size();
        for(int j = 0; j < n / 2; ++j) {
            swap(matrix[i][j], matrix[i][n -j - 1]);
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
        
    };
    rotate(matrix);
    for(int i = 0; i < matrix.size(); ++i) {
        for(int j =0; j < matrix[i].size(); ++j) {
            cout<<matrix[i][j]<<" ";
        }

        cout<<"\n";
    }

    return 0;
}