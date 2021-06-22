#include <iostream>
#define N 4

using namespace std;


void rotateMatrix(int mat[][N]){
    for(int i = 0; i < N/2; ++i){
        for(int j = i;j < N - i - 1; ++j){
            int temp = mat[i][j];
            mat[i][j] = mat[j][N - 1 - i];
            mat[j][N - 1 - i] = mat[N - 1 - i][N - 1 - j];
            mat[N - 1 - i][N - 1 - j] = mat[N - 1 - j][i];
            mat[N - 1 - j][i] = temp;
        }
    }
}


void displayMatrix(int mat[][N]){
    for(int i = 0;i < N; ++i){
        for(int j = 0;j < N; ++j)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}



int main()
{
    int mat[N][N] = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 }
    };

   
    rotateMatrix(mat);

    displayMatrix(mat);

    return 0;
}
