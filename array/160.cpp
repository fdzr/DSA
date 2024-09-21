#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
vi findErrorNums(vector<int>& nums) {
    vi freq(nums.size() + 1, 0);
    vi answer;
    int foundRepeatedElem = 0, missingElem = 0;

    for(const auto & value: nums)
        freq[value]++;

    for(int i = 1; i <= freq.size(); ++i) {
        if(freq[i] == 2)
            foundRepeatedElem = i;
        if(freq[i] == 0)
            missingElem = i;

        if(foundRepeatedElem && missingElem)
            break;
    }

    return {foundRepeatedElem, missingElem};
}

int main() {
    vi elems = {1,1};
    for(auto e: findErrorNums(elems))
        cout<<e<<" ";

    return 0;
}