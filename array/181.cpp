#include <bits/stdc++.h>

using namespace std;


int dominantIndex(vector<int>& nums) {
    vector<int>::iterator maxElement = max_element(nums.begin(), nums.end());
    int index = distance(nums.begin(), maxElement);

    for(int i = 0; i < nums.size(); ++i) {
        if(nums[i] == *maxElement)
            continue;
        if(*maxElement < nums[i] * 2)
            return -1;
    }

    return index;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    vector<int> nums {1,2,3,4};
    cout<<boolalpha<<dominantIndex(nums);


    return 0;
}