#include <bits/stdc++.h>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    auto low = lower_bound(nums.begin(), nums.end(), target);
    if (low == nums.end())
        return nums.size();
    
    return distance(nums.begin(), low);
}


int main() {
    vector<int> vc = {1,3,4,6};
    int target = 5;
    cout<<searchInsert(vc, target);

    return 0;
}