#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

vector<int> sortedSquares(vector<int>& nums) {
    vi ans;
    int i = 0, j = nums.size() - 1;

    while(i != j) {
        int iz = pow(nums[i], 2);
        int de = pow(nums[j], 2);
        if(de >= iz)
            ans.insert(ans.begin(), de), --j;
        else
            ans.insert(ans.begin(), iz), ++i;
    }

    ans.insert(ans.begin(), pow(nums[i], 2));

    return ans;
}




int main() {
    vi nums = {-7,-3,2,3,11};
    for(auto elem: sortedSquares(nums))
        cout<< elem<<" ";


    return 0;
}