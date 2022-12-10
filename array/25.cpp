#include <bits/stdc++.h>
#include "../common/array.h"

using namespace std;
using namespace ARRAY;

vector<int> decode(vector<int>& encoded, int first) {
    vector<int> ans;
    int original = first;
    for(int i = 0; i < encoded.size(); ++i) {
        ans.push_back(first ^ encoded[i]);
        first = ans[i];
    }
    
    ans.insert(ans.begin(), original);
    
    return ans;     
}

int main() {
    vector<int> vc = {0,0,5,3}, ans;
    int first = 7;
    ans = decode(vc, first);
    cout<<ans;

    return 0;
}