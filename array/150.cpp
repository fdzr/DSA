//
// Created by fzamora on 01-07-24.
//

#include <bits/stdc++.h>

using namespace std;

int duplicateNumbersXOR(vector<int>& nums) {
    unordered_map<int, int> um;
    int answer = 0;

    for(auto elem: nums) {
        um[elem]++;
        if(um[elem] == 2)
            answer ^= elem;
    }

    return answer;
}

int main () {
    vector<int> nums = {1,2,2, 1};
    cout<<duplicateNumbersXOR(nums);

    return 0;
}