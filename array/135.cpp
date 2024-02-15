// https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/

#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
vvi findWinners(vvi& matches) {
    unordered_map<int, int> um;
    vi losers, winners;
    vvi ans;

    for(auto match: matches) {
        um[match[0]] = 0;
        um[match[1]] = 0;
    }

    for(auto match: matches)
        um[match[1]] --;
    
    for_each(um.begin(), um.end(), 
        [&losers, & winners](const pair<int, int> p) {
            if(p.second == 0)
                winners.push_back(p.first);
            if(p.second == -1)
                losers.push_back(p.first);
        });

    sort(winners.begin(), winners.end());
    sort(losers.begin(), losers.end());

    ans.push_back(winners);
    ans.push_back(losers);

    return ans;

}

ostream &operator<<(ostream &out, vi v) {
    out<<"["<<v[0];
    for(int i =1; i < v.size(); ++i)
        out<<", "<<v[i];

    out<<"]"<<endl;
    return out;
}


int main() {
    vvi matches = {
        {1, 3},
        {2, 3},
        {3, 6},
        {5, 6},
        {5, 7},
        {4, 5},
        {4, 8},
        {4, 9},
        {10, 4},
        {10, 9},
    }; 

    vvi ans = findWinners(matches);
    cout<<ans[0];
    cout<<ans[1];

    return 0;
}