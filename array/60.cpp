#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vi kWeakestRows(vector<vector<int>>& mat, int k) {
    multiset<pair<int, int>> conj;
    vi ans;
    int index = 0;
    for(auto row: mat) {
        int sum = accumulate(row.begin(), row.end(), 0);
        conj.insert({sum, index++});
    }

    auto it = conj.begin();
    for(int i = 0; i < k; ++i) {
        ans.push_back(it->second);
        ++it;
    }

    return ans;
}


int main(){
    vvi mat = {{1,0,0,0},
               {1,1,1,1},
               {1,0,0,0},
               {1,0,0,0}};
    for(auto elem: kWeakestRows(mat, 2))
        cout<<elem<<" ";

    return 0;
}