#include <bits/stdc++.h>

using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int maxCandies = *max_element(candies.begin(), candies.end());
    vector<bool> ans;

    for(auto candie: candies)
        ans.push_back((candie + extraCandies) >= maxCandies);
    
    return ans;
}

int main() {
    vector<int> vc = {4,2,1,1,2};
    int extraCandies = 1;
    vector<bool> ans = kidsWithCandies(vc, extraCandies);

    for(auto a: ans)
        cout<<a<<" ";


    return 0;
}