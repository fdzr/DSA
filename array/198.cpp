#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> answer;
    vector<int> initialInterval = intervals[0];

    for (int i = 1; i < intervals.size(); ++i) {
        vector<int> temp = intervals[i];
        if (temp[0] == initialInterval[0]) {
            initialInterval[1] = temp[1];
        } else if (temp[0] <= initialInterval[1]) {
            initialInterval[1] = (temp[0] == initialInterval[1])  ? temp[1]
                                 : (initialInterval[1] > temp[1]) ? initialInterval[1]
                                                                  : temp[1];
        } else {
            answer.push_back(initialInterval);
            initialInterval = temp;
        }
    }

    answer.push_back(initialInterval);

    return answer;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    auto ans = merge(intervals);

    for (const auto& v : ans) {
        for (const auto& e : v) {
            cout << e << " ";
        }
        cout << "\n";
    }

    return 0;
}