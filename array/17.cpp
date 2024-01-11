#include <bits/stdc++.h>
#include "../common/array.h"

using namespace std;
using namespace ARRAY;

vector<int> runningSum(vector<int> &nums) {
    vector<int> ans;
    int sum = 0;
    for(auto a: nums) {
        sum += a;
        ans.push_back(sum);
    }

    return ans;
}

int main() {
    vector<int> vc = {1,2,3,4,5};
    vector<int> ans = runningSum(vc);
    cout<<ans;

    return 0;
}
