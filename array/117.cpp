#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
int removeDuplicates(vector<int>& nums) {
    map<int, vi> um;
    int originalSize = nums.size();

    for(auto elem: nums) {
        if(um[elem].size() < 2)
            um[elem].push_back(elem);
    }

    nums.clear();
    for(auto &[key, values]: um) {
        copy(values.begin(), values.end(), back_inserter(nums));
    }

    int n = originalSize - nums.size();
    int answer = nums.size();
    for(int i = 0; i < n; ++i)
        nums.push_back(0);

    return answer;
}

int main () {
    vi nums = {0,1};
    cout<<removeDuplicates(nums);

    return 0;
}