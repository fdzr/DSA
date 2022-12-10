#include <bits/stdc++.h>
#include "../common/array.h"

using namespace std;
using namespace ARRAY;


vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    vector<int> ans;
    for(int i=0;i<index.size(); ++i) {
        if(ans.empty())
            ans.push_back(nums[0]);
        else
            ans.insert(ans.begin() + index[i], nums[i]);
    }

    return ans;
}


int main() {
    vector<int> vc = {1};
    vector<int> index = {0};
    vector<int> ans;

    ans = createTargetArray(vc, index);
    cout<<ans;

    return 0;
}