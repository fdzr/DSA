#include <bits/stdc++.h>

using namespace std;

vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
    vector<int> answer(k);
    unordered_map<int, set<int>> um;

    for(auto item: logs) {
        um[item[0]].insert(item[1]);
    }

    for(auto &[key, conj]: um)
        answer[conj.size() - 1]++;

    return answer;
}

int main() {
    vector<vector<int>> logs = {{1,1},{2,2},{2,3}};
    for(auto val: findingUsersActiveMinutes(logs, 4))
        cout<<val<<" ";

    return 0;
}