#include <bits/stdc++.h>
#include "../common/array.h"

using namespace std;
using namespace ARRAY;


vector<int> getConcatenation(vector<int>& nums) {
    vector<int> ans = nums;
    ans.insert(ans.end(), ans.begin(), ans.end());

    return ans;
}


int main() {
    vector<int> vc = {1,3,2,1}, ans;
    ans = getConcatenation(vc);
    cout<<ans;


    return 0;
}