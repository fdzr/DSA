#include <bits/stdc++.h>

using namespace std;

vector<string> findRelativeRanks(vector<int>& score) {
    priority_queue<int> pq;
    vector<string> ans;
    unordered_map<int, string> um;

    for(const auto & elem: score)
        pq.push(elem);

    int index = 0;
    while(!pq.empty()) {
        int elem = pq.top();
        pq.pop();

        if(index == 0)
            um[elem] = "Gold Medal";
        else if(index == 1)
            um[elem] = "Silver Medal";
        else if(index == 2)
            um[elem] = "Bronze Medal";
        else
            um[elem] = to_string(index + 1);

        ++index;
    }

    for(const int &elem: score){
        ans.push_back(um[elem]);
        
    }

    return ans;
    
}

int main () {
    vector<int> nums{10,3,8,9,4};
    for(const auto& elem: findRelativeRanks(nums))
        cout<<elem<<" ";
    cout<<"\n";

    return 0;
}