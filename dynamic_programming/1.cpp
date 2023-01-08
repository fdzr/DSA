#include "bits/stdc++.h"

using namespace std;

using vi = vector<int>;

int minCostClimbingStairs(vector<int>& cost) {
    vi ans(cost.size() + 1, 0);
    ans[0] = cost[0];
    ans[1] = cost[1];
    int i;

    for(i = 2; i < cost.size(); ++i)
        ans[i] = cost[i] + min(ans[i -1], ans[i - 2]);

    ans[i] = min(ans[i-1], ans[i-2]);

    return ans[ans.size() - 1];
}

int main() {
    vi cost = {10, 15, 20};
    cout<<minCostClimbingStairs(cost);

    return 0;
}