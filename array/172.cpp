#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;
int findShortestSubArray(vector<int>& nums) {
    vvi ans(50000);
    int cont = 0;
    int distance = INT_MAX;
    int start, end;

    for(int i = 0; i < nums.size(); ++i) {
        ans[nums[i]].push_back(i);
        int freq = ans[nums[i]].size();
        start = *ans[nums[i]].begin();
        end = *(--ans[nums[i]].end());

        if(freq > cont) {
            distance = end - start;
            cont = freq;
        }
        else if (freq == cont) {
            distance = (end - start) < distance? end - start: distance;
        }
    }

    return distance + 1;
}

int main() {
    vi nums = {1,2,2,3,1, 49999,49999, 49999};
    cout<<findShortestSubArray(nums);

    return 0;
}