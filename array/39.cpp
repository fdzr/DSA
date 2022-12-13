#include <bits/stdc++.h>

using namespace std;


int diagonalSum(vector<vector<int>>& mat) {
    int cont = 0;
    int n = mat.size();
    for(int i = 0; i < n; ++i)
        cont += mat[i][i];

    for(int i = n - 1; i >= 0 ; --i)
        cont += mat[n - i - 1][i];

    cont -= (mat.size() % 2 == 1)? mat[mat.size()/2][mat.size()/2]:0;
    return cont;
}


int main() {
    vector<vector<int>> mat = {{7,3,1,9},
                               {3,4,6,9},
                               {6,9,6,6},
                               {9,5,8,5}};
    cout<<diagonalSum(mat);


    return 0;
}