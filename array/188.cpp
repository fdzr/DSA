#include <bits/stdc++.h>

using namespace std;

using vvi = vector<vector<int>>;

vector<int> mergeKSortedList(vvi lists) {
    vector<int> answer(lists.size() * lists[0].size());
    vector<int> indexes(lists.size());

    for (int i = 0; i < lists.size(); ++i) {
        indexes[i] = lists[i].size() - 1;
    }

    for (int i = answer.size() - 1; i >= 0; --i) {
        int index = -1;
        int maxElement = INT_MIN;
        for (int j = 0; j < indexes.size() ; ++j) {
            if (indexes[j] >= 0 && lists[j][indexes[j]] > maxElement) {
                maxElement = lists[j][indexes[j]];
                index = j;
            }
        }

        indexes[index]--;
        answer[i] = maxElement;
    }

    return answer;
}

int main() {
    vvi lists = {{10, 20, 30, 40},
                 {15, 25, 35, 45},
                 {27, 29, 37, 48},
                 {32, 33, 39, 50},
                 {16, 18, 22, 28}};

    for (int e : mergeKSortedList(lists)) cout << e << " ";

    return 0;
}