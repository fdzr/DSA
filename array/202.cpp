#include <bits/stdc++.h>

using namespace std;

int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
    sort(processorTime.begin(), processorTime.end());
    sort(tasks.begin(), tasks.end(), greater<int>());
    int index = 0;
    int minTime = INT_MIN;

    for (int i = 0; i < processorTime.size(); ++i) {
        minTime = max(minTime, processorTime[i] + tasks[index]);
        index += 4;
    }

    return minTime;
}

int main() {
    vector<int> t = {2, 3, 1, 2, 5, 8, 4, 3};
    vector<int> pt = {10, 20};

    cout << minProcessingTime(pt, t);

    return 0;
}