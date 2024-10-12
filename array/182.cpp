#include <bits/stdc++.h>

using namespace std;

long long pickGifts(vector<int>& gifts, int k) {
    priority_queue<int>pq;
    vector<int> ans;

    for(const auto& value: gifts)
        pq.push(value);

    while(k-- > 0) {
        int elem = pq.top();
        pq.pop();
        int squareRoot = static_cast<int>(sqrt(elem));
        pq.push(squareRoot);
    }

    long long int sum = 0;

    while(!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }

    return sum;
}

int main() {
    vector<int> nums = {1,1,1,1};
    cout<<pickGifts(nums, 4);

    return 0;
}