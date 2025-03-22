#include <bits/stdc++.h>

using namespace std;

int maximumCandies(vector<int>& candies, long long k) {
    long long sum = accumulate(candies.begin(), candies.end(), 0LL);
    if (sum < k) return 0;

    long long sol = 0;
    long long L = 1;
    long long R = *max_element(candies.begin(), candies.end());

    while (L <= R) {
        long long count = 0;
        long long M = L + (R - L) / 2;

        for (const auto& e : candies) {
            count += static_cast<int>(e / M);
        }

        if (count >= k) {
            L = M + 1;
            sol = max(sol, M);
        } else {
            R = M - 1;
        }
    }

    return sol;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> candies = {4, 7, 5};
    int k = 16;
    cout << maximumCandies(candies, k);

    return 0;
}