#include <bits/stdc++.h>
#include "../common/array.h"

using namespace std;
using namespace ARRAY;

vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> ans;
    for(int i=0; i < n; ++i) {
        ans.push_back(nums[i]);
        ans.push_back(nums[i + n]);
    }
    return ans;
}


int main() {
    vector<int> vc = {1,2,3,4,4,3,2,1};
    int n = 4;
    vector<int> ans = shuffle(vc, n);
    cout<<ans;


    return 0;
}