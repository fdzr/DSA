#include <bits/stdc++.h>

using namespace std;

using vvi = vector<vector<int>>;

void printMatrix(vvi matrix){
    for(auto row: matrix) {
        for(auto elem: row)
            cout<<elem<<" ";

        cout<<endl;
    }    
}

class SubrectangleQueries {
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
       matrix = rectangle; 
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(int i = row1; i <= row2; ++i)
            for(int j = col1; j <= col2; ++j)
                matrix[i][j] = newValue;
    }
    
    int getValue(int row, int col) {
        return matrix[row][col];
    }

    vvi getRectangle() const {return matrix; }

private:
    vvi matrix;
};

int main () {
    vvi matrix = {
        {1,2,1},
        {4,3,4},
        {3,2,1},
        {1,1,1}};

    SubrectangleQueries obj(matrix);
    printMatrix(obj.getRectangle());
    cout<<endl;
    cout<<obj.getValue(0, 2)<<endl;
    obj.updateSubrectangle(0, 0, 3, 2, 5);
    cout<<obj.getValue(0, 2)<<endl;
    cout<<obj.getValue(3, 1)<<endl; 
    obj.updateSubrectangle(3, 0, 3, 2, 10);
    cout<<obj.getValue(3, 1)<<endl;
    cout<<obj.getValue(0, 2)<<endl; 


    return 0;
}