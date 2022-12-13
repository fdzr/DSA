#include <bits/stdc++.h>

using namespace std;

int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int cont = 0;
    for(int i = 1; i < points.size(); ++i) {
        auto a = points[i];
        auto b = points[i-1];
        pair<int, int> c;
        c.first = abs(b[0] - a[0]);
        c.second = abs(b[1] - a[1]);
        cont += max(c.first, c.second);

    }
    return cont;
}



int main() {
    vector<vector<int>> points{{3,2},
                               {-2,-2},
                               };
    cout<<minTimeToVisitAllPoints(points);

    return 0;
}