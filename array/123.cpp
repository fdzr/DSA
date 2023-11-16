#include <bits/stdc++.h>

using namespace std;

int findTheWinner(int n, int k) {
    vector<int> players(n, 0);
    iota(players.begin(), players.end(), 1);
    int index = 0;

    while(players.size() != 1) {
        index = (index + k - 1) % players.size();
        
        erase(players, players[index]);

    }

    return players.back();
}

int main() {
    int n = 5, k = 2;
    cout<<findTheWinner(n, k);

    return 0;
}