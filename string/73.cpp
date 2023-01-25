//
// Created by fzamora on 25-01-23.
//

#include "bits/stdc++.h"

using namespace std;

bool squareIsWhite(string coordinates) {
    vector<int> rows = {0,1,0,1,0,1,0,1};
    int startPosition = rows[coordinates[0] - 97];
    int column = (coordinates[1] - '0') - 1;
    column = rows[column];
    bool flag;

    if(column % 2 == 1)
        flag = !startPosition;
    else
        flag = startPosition;

    return flag;
}

int main() {
    string coordinate = "f4";
    cout<<squareIsWhite(coordinate);

    return 0;
}