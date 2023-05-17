#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vb = vector<bool>;

bool check(vi nums) {
    sort(nums.begin(), nums.end());
    int diff = nums[1] - nums[0];
    for(int i = 1; i < nums.size(); ++i)
        if(nums[i] - nums[i - 1] != diff)
            return false;

    return true;
}

vector<bool> checkArithmeticSubarrays(vi& nums, vi& l, vi& r) {
    vb answer(l.size());
    for(int i = 0; i < l.size(); ++i) {
        vi temp(nums.begin() + l[i], nums.begin() + r[i] + 1);     
        answer[i] = check(temp);
    }
    
    return answer;
}

int main() {
    vi nums = {-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10};
    vi l = {0,1,6,4,8,7};
    vi r = {4,4,9,7,9,10};
    for(auto elem: checkArithmeticSubarrays(nums, l, r))
        cout<<elem<<" ";

    return 0;
}