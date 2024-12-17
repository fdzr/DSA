#include <bits/stdc++.h>

using namespace std;

string repeatLimitedString(string s, int repeatLimit) {
    unordered_map<char, int> um;
    for (int i = 0; i < s.size(); ++i) um[s[i]]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;

    for (const auto& item : um) {
        pq.push({item.first, item.second});
    }

    string ans = "";

    while (!pq.empty()) {
        auto a = pq.top();
        pq.pop();

        int minQuantity = min(repeatLimit, a.second);

        ans += string(minQuantity, char(a.first));

        if (a.second - minQuantity > 0) {
            if (pq.empty()) break;

            auto b = pq.top();
            pq.pop();

            ans += string(1, char(b.first));
            if (b.second - 1 > 0) pq.push({b.first, b.second - 1});

            pq.push({a.first, a.second - minQuantity});
        }
    }

    return ans;
}

int main() {
    string s = "aababab";
    int k = 2;

    cout << repeatLimitedString(s, k);

    return 0;
}