#include <bits/stdc++.h>

using namespace std;

int countDistinctIntegers(vector<int>& nums) {
    vector<int> temp;
    for(auto elem: nums){
        string newNum = to_string(elem);
        reverse(newNum.begin(), newNum.end());
        temp.push_back(stoi(newNum));
    }

    copy(temp.begin(), temp.end(), back_inserter(nums));
    unordered_set<int> answer(nums.begin(), nums.end());
    return answer.size();
}

int main() {
    vector<int> nums = {1,13,10,12,31};
    cout<<countDistinctIntegers(nums);

    return 0;
}