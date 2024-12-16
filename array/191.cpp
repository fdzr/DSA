#include <bits/stdc++.h>

using namespace std;

void sortKSortedArray(vector<int> &arr, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i <= k; ++i) {
        pq.push(arr[i]);
    }

    int index = 0;
    for (int i = k + 1; i < arr.size(); ++i) {
        arr[index++] = pq.top();
        pq.pop();

        pq.push(arr[i]);
    }

    while(!pq.empty()) {
        arr[index++] = pq.top();
        pq.pop();
    }
}

int main() {
    vector<int> arr = {3, 4, 1, 2, 6, 7, 5, 10, 8, 9};

    sortKSortedArray(arr, 2);

    for (const auto &elem : arr) cout << elem << " ";

    return 0;
}