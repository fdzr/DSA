#include <bits/stdc++.h>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> freq;

    for(const auto& elem: nums) {
        auto item = freq.insert(elem);

        if(item.second == false)
            return true;
    }

    return false;

}

int main() {
    vector<int> nums {1,2,3,4,5,6,6, 10000};
    cout<<boolalpha<<containsDuplicate(nums);


    return 0;
}