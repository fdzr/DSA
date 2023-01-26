#include <bits/stdc++.h>

using namespace std;

using pi = pair<int, int>;

bool judgeCircle(string moves) {
    pi origin{0, 0};

    for(auto move: moves) {
        if(move == 'R')
            origin.first += 1;
        else if(move == 'L')
            origin.first -= 1;
        else if(move == 'U')
            origin.second += 1;
        else if(move == 'D')
            origin.second -= 1;
    }

    return origin == make_pair(0, 0);
}


int main() {
    string moves = "LL";
    cout<<judgeCircle(moves);

    return 0;
}