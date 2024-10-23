#include <bits/stdc++.h>

using namespace std;

int specialArray(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int  n = nums.size();
    int cant = n;

    for(int i = 0; i < n; ++i) {
        if(nums[i] == 0) {
            --cant;
            continue;
        }

        if((nums[i] >= cant && i - 1 > 0 && nums[i - 1] < cant) || (nums[i] >= cant && i - 1 < 0))
            break;

        --cant;
    }

    return cant != 0 ? cant: -1;
}

int main() {
    vector<int> nums{0, 0, 1,2,3,4,5,6,7,8};
    cout<<specialArray(nums);

    return 0;
}