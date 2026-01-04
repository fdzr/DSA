#include <bits/stdc++.h>

using namespace std;

using ll = long long int;

long long maximumHappinessSum(vector<int>& happiness, int k) {
    ll answer = 0;
    int decrement = 0;
    sort(happiness.begin(), happiness.end(), greater<int>());

    for (int i = 0; i < k; ++i) {
        if (i != 0) {
            answer += max(happiness[i] - decrement, 0);
        } else {
            answer += happiness[i];
        }
        decrement += 1;
    }

    return answer;
}

int main() {
    vector<int> v = {1, 2, 3};
    int k = 2;

    cout << maximumHappinessSum(v, k);

    return 0;
}