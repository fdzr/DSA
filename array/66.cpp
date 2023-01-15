#include <bits/stdc++.h>

using namespace std;

using pi = pair<int, int>;
using vpi = vector<pi>;
using vvi = vector<vector<int>>;

auto cmp = [](const pi &lhs, const pi& rhs) {
    return lhs.second < rhs.second;
};

int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    priority_queue<pi, vpi, decltype(cmp)> cola(cmp);
    int ans = 0;

    for(auto item: boxTypes) {
        cola.push(make_pair(item[0], item[1]));
    }

    while(truckSize > 0 && !cola.empty()) {
        pi item = cola.top();
        cola.pop();
        if(item.first <= truckSize) {
            ans += item.first * item.second;
            truckSize -= item.first;
        }
        else {
            ans += truckSize * item.second;
            truckSize = 0;
        }

    }    

    return ans;
}


int main() {
    vvi boxTypes = {{5,10},{2,5},{4,7},{3,9}};
    int truckSize = 10;
    cout<<maximumUnits(boxTypes, truckSize);

    return 0;
}