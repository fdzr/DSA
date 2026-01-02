# include<bits/stdc++.h>

using namespace std;

int repeatedNTimes(vector<int>& nums) {
    unordered_map<int, int> um;
    int answer;

    for(const auto &e: nums) {
        um[e]++;
        if (um[e] == nums.size() / 2) {
            answer = e;
            break;
        }
    }
    
    
    return answer;
}

int main() {
    vector<int> nums = {5,1,5,2,5,3,5,4};
    cout << repeatedNTimes(nums);


    return 0;
}