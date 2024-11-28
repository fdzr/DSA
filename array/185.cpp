#include <bits/stdc++.h>

// https://www.geeksforgeeks.org/find-the-maximum-amount-that-can-be-collected-by-selling-movie-tickets/?ref=oin_asr1

using namespace std;

int maximumProfit(vector<int> seats, int N) {
    priority_queue<int> pq;
    int sum = 0;

    for (const auto& elem : seats)
        pq.push(elem);

    for (int i = 0; i < N; ++i) {
        if (!pq.empty()) {
            int maxValue = pq.top();
            sum += maxValue;

            pq.pop();
            --maxValue;
            pq.push(maxValue);
        }
    }

    return sum;
}

int main() {
    int N = 3;
    vector<int> seats = {1, 2, 4};

    cout<<maximumProfit(seats, N);

    return 0;
}