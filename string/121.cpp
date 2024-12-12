#include <bits/stdc++.h>

using namespace std;

void dfs(int start, string s, unordered_set<string> &uniqueSubs, int &maxQuantity) {
    if (start == s.size()) {
        maxQuantity = max(maxQuantity, static_cast<int>(uniqueSubs.size()));
        return;
    }

    for (int i = 1; i <= s.size(); ++i) {
        string chunk = s.substr(start, i);
        if (uniqueSubs.count(chunk) == 0) {
            uniqueSubs.insert(chunk);
            dfs(start + chunk.size(), s, uniqueSubs, maxQuantity);
            uniqueSubs.erase(chunk);
        }
    }
}

void DFSOptimized(int start, string s, unordered_set<string> &uniqueSubs,
                  int &maxQuantity) {
    if (start >= s.size()) {
        maxQuantity = max(maxQuantity, static_cast<int>(uniqueSubs.size()));
        return;
    }

    for (int i = start; i < s.size(); ++i) {
        string chunk = s.substr(start, i - start + 1);
        if (uniqueSubs.insert(chunk).second) {
            DFSOptimized(i + 1, s, uniqueSubs, maxQuantity);
            uniqueSubs.erase(chunk);
        } else {
            continue;
        }
    }
}

int maxUniqueSplit(string s) {
    unordered_set<string> uniqueSubs;
    int maxQuantity = -1;

    // dfs(0, s, uniqueSubs, maxQuantity);
    DFSOptimized(0, s, uniqueSubs, maxQuantity);

    return maxQuantity;
}

int main() {
    string s = "aa";
    cout << maxUniqueSplit(s);

    return 0;
}