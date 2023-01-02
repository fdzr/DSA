#include <bits/stdc++.h>

using namespace std;


int sumOfUnique(vector<int>& nums) {
    unordered_map<int, int> um;
    int sum = 0;
    for(auto elem: nums)
        um[elem]++;

    for(auto & [k, v]: um) {
        if(v == 1)
            sum += k;
    }

    return sum;
}


using vi = vector<int>;
int main() {
    vi nums = {1,2,2,3};
    cout<<sumOfUnique(nums);

    return 0;
}