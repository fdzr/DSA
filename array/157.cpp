#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
int maxProfitAssignment(vi& difficulty, vi& profit, vi& worker) {
    vector<pair<int, int>> jobsAndDifficulty;
    int maxProfit = 0;

    for(int i = 0; i < difficulty.size(); ++i) {
        jobsAndDifficulty.emplace_back(difficulty[i], profit[i]);
    }

    sort(jobsAndDifficulty.begin(), jobsAndDifficulty.end());
    sort(worker.begin(), worker.end());

    int index = 0;
    int acc = 0;
    int bestProfit = 0;
    for(int i = 0; i < worker.size(); ++i) {

        while (index < jobsAndDifficulty.size() && jobsAndDifficulty[index].first <= worker[i]) {
            bestProfit = max(bestProfit, jobsAndDifficulty[index].second);
            index++;
        }

        acc += bestProfit;
    }

    return acc;
}

int main(){
    vi d = {2,4,6,8,10};
    vi p = {10,20,30,40,50};
    vi w = {4,5,6,7};

    cout<<maxProfitAssignment(d, p, w);

    return 0;
}