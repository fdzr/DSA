#include <bits/stdc++.h>

using namespace std;

void updateWaitTime(unordered_map<char, int> &waitTime, char c) {
    for (auto &[k, v] : waitTime) {
        if (k != c && v > 0) --v;
    }
}

int computeInterval(unordered_map<char, int> &freq, int n, int acc) {
    int idle = 0;
    int m = n;
    char previous = ' ';

    unordered_map<char, int> waitTimeByTask;
    vector<pair<char, int>> copyFreq(26, {'0', 0});
    for (const auto &item : freq) {
        copyFreq[item.first - 65] = {item.first, item.second};
    }

    sort(copyFreq.begin(), copyFreq.end(),
         [](const auto &a, const auto &b) { return a.second > b.second; });

    while (acc > 0) {
        bool executedTask = false;

        for (int i = 0; i < copyFreq.size(); ++i) {
            if (copyFreq[i].second > 0 && copyFreq[i].first != previous) {
                if (waitTimeByTask[copyFreq[i].first] == 0) {
                    waitTimeByTask[copyFreq[i].first] = m;
                    copyFreq[i].second--;
                    acc--;
                    updateWaitTime(waitTimeByTask, copyFreq[i].first);
                    executedTask = true;
                    previous = copyFreq[i].first;

                    sort(
                        copyFreq.begin(), copyFreq.end(),
                        [](const auto &a, const auto &b) { return a.second > b.second; });

                    break;
                }
            }
        }

        if (executedTask == false) {
            ++idle;
            
            updateWaitTime(waitTimeByTask, 'a');
        }
    }

    return idle;
}

int leastInterval(vector<char> &tasks, int n) {
    unordered_map<char, int> freq;
    for (int i = 0; i < tasks.size(); ++i) ++freq[tasks[i] - 0];

    int idle = computeInterval(freq, n, tasks.size());

    return tasks.size() + idle;
}

int main() {
    vector<char> tasks = {'A', 'A', 'A'};
    int n = 1;

    cout << leastInterval(tasks, n);
    return 0;
}