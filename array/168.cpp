#include <bits/stdc++.h>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> um;

    for(int i = 0; i < nums.size(); ++i) {
        if(um.count(nums[i]) > 0 && abs(um[nums[i]] - i) <= k)
            return true;
        else {
            um[nums[i]] = i;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    vector<int> nums = {1,2,3,1,2,3};
    int k = 2;

    cout<<boolalpha<<containsNearbyDuplicate(nums, k);

    return 0;
}