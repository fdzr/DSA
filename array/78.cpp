//
// Created by fzamora on 25-01-23.
//
#include <bits/stdc++.h>

using namespace std;

int largestAltitude(vector<int>& gain) {
    vector<int> ans(gain.size() + 1);
    for(int i = 0; i < gain.size(); ++i) {
        ans[i+1] += ans[i] + gain[i];

    }

    return *max_element(ans.begin(), ans.end());
}

int main() {
    vector<int> gain = {-4,-3,-2,-1,4,3,2};
    cout<<largestAltitude(gain);

    return 0;
}