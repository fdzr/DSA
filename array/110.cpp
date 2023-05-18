//
// Created by fzamora on 18-05-23.
//
#include <bits/stdc++.h>

using namespace std;

int maxCoins(vector<int>& piles) {
    sort(piles.begin(), piles.end());
    int originalSize = piles.size();
    int n = piles.size() / 3;
    int answer = 0;

    while(n-- > 0) {
        answer += piles[originalSize - 2];
        originalSize -= 2;
    }

    return answer;
}

int main() {
    vector<int> piles = {9,8,7,6,5,1,2,3,4};
    cout<<maxCoins(piles);

    return 0;
}