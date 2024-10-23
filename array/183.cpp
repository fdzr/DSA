// https://leetcode.com/problems/fair-candy-swap/
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
vector<int> fairCandySwap(vi& aliceSizes, vi& bobSizes) {
    int amountAlice = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
    int amountBob = accumulate(bobSizes.begin(), bobSizes.end(), 0);
    int half = (amountAlice + amountBob) / 2;
    int diff = abs(amountAlice - half);

    for(int i = 0; i < aliceSizes.size(); ++i) {
        for(int j = 0; j < bobSizes.size(); ++j) {
            if(amountAlice < half) {
                if(diff + aliceSizes[i] == bobSizes[j])
                    return {aliceSizes[i], bobSizes[j]};
            } else {
                if(diff + bobSizes[j] == aliceSizes[i])
                    return {aliceSizes[i], bobSizes[j]};
            }
        }
    }


    return {0, 0};
}

int main() {
    vector<int> alice = {1,3} ;
    vector<int> bob = {2};

    auto ans = fairCandySwap(alice, bob);
    cout<<ans[0]<<" "<<ans[1];

    return 0;
}