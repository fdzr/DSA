#include <bits/stdc++.h>

using namespace std;

string lastNonEmptyString(string s) {
    unordered_map<char, pair<int, vector<int>>> um;
    vector<pair<char, int>> maximos;

    for(int i = 0; i < s.length(); ++i) {
        um[s[i]].first++;
        um[s[i]].second.push_back(i);
    }

    auto maxElement = max_element(um.begin(), um.end(), [](const auto& lhs, const auto& rhs){
        return lhs.second.first < rhs.second.first;
    });

    for_each(um.begin(), um.end(), [&maximos, maxElement](const auto& obj){
        if (obj.second.first == maxElement->second.first)
            maximos.emplace_back(obj.first, obj.second.second.back());
    });

    sort(maximos.begin(), maximos.end(), [](const auto& l, const auto& r){
        return l.second < r.second;
    });

    string ans = "";
    for(int i = 0; i < maximos.size(); ++i) {
        ans.push_back(maximos[i].first);
    }

    return ans;

}

int main() {
    string s = "z";
    cout<<lastNonEmptyString(s);

    return 0;
}