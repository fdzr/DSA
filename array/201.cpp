#include <bits/stdc++.h>

using namespace std;

using vvi = vector<vector<int>>;
using vi = vector<int>;

vvi mergeIntervals(vvi &meetings) {
    sort(meetings.begin(), meetings.end(), [](const auto &a, const auto &b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    });

    vvi ans;

    vector<int> initialInterval = meetings[0];

    for (int i = 1; i < meetings.size(); ++i) {
        vector<int> temp = meetings[i];

        if (temp[0] <= initialInterval[1] || temp[0] - initialInterval[1] == 1) {
            if (temp[1] >= initialInterval[1])
                initialInterval[1] = temp[1];
        } else {
            ans.push_back(initialInterval);
            initialInterval = temp;
        }
    }

    ans.push_back(initialInterval);

    return ans;
}

int countDays(int days, vector<vector<int>> &meetings) {
    vvi schedule = mergeIntervals(meetings);
    vi initial = schedule[0];
    int cont = initial[0] - 1;

    for (int i = 1; i < schedule.size(); ++i) {
        cont += schedule[i][0] - initial[1] - 1;
        initial = schedule[i];
    }

    cont += (days - schedule[schedule.size() - 1][1]);

    return cont;
}

int main() {
    vvi meetings = {{3, 49},  {23, 44}, {21, 56}, {26, 55},
                    {23, 52}, {2, 9},   {1, 48},  {3, 31}};
    int k = 57;

    // sort(meetings.begin(), meetings.end(), [](const auto &a, const auto &b) {
    //     if (a[0] == b[0]) return a[1] < b[1];
    //     return a[0] < b[0];
    // });

    // meetings = mergeIntervals(meetings);

    // for(const auto &v: meetings) {
    //     cout<< "[" <<v[0] << " "<<v[1] <<"]"<<"\n";
    // }

    cout << countDays(k, meetings);

    return 0;
}