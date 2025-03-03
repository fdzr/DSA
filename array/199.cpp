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

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    bool inserted = false;
    vector<vector<int>> answer;

    if (intervals.size() == 0) {
        return {newInterval};
    }

    for (int i = 0; i < intervals.size(); ++i) {
        if (!inserted) {
            if (newInterval[0] < intervals[i][0]) {
                answer.push_back(newInterval);
                inserted = true;
            } else if (newInterval[0] == intervals[i][0] &&
                       newInterval[1] <= intervals[i][1]) {
                answer.push_back(newInterval);
                inserted = true;
            }
        }

        answer.push_back(intervals[i]);
    }

    if (!inserted) answer.push_back(newInterval);

    return merge(answer);
}

int main() {
    vector<vector<int>> intervals = {{1, 5}};
    vector<int> newInterval = {2, 7};

    for (const auto& v : insert(intervals, newInterval)) {
        for (const auto& e : v) {
            cout << e << " ";
        }

        cout << "\n";
    }

    

    return 0;
}