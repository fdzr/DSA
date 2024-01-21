#include <bits/stdc++.h>

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>> pq;
    int ans;

    for(auto elem: nums)
        pq.push(elem);

    while(k--) {
        ans = pq.top();
        pq.pop();
    }

    return ans;
}

int main() {
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    cout<<findKthLargest(nums,  k);


    return 0;
}