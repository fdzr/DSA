#include <bits/stdc++.h>

using namespace std;

bool partitionKEqualSum(vector<int> &arr, vector<int> &subSets, int k,
                        vector<int> &visited, int &index) {
    if (index == subSets.size()) {
        return all_of(subSets.begin(), subSets.end(),
                      [k](const int &elem) { return elem == k; });
    }

    bool inSubset = false;

    for (int i = 0; i < arr.size(); ++i) {
        if (visited[i] == 1) continue;
        if (subSets[index] + arr[i] > k) continue;

        inSubset = true;
        visited[i] = 1;
        subSets[index] += arr[i];

        if (partitionKEqualSum(arr, subSets, k, visited, index) == true) return true;

        visited[i] = 0;
        subSets[index] -= arr[i];
    }

    if (!inSubset) {
        index += 1;
        if (partitionKEqualSum(arr, subSets, k, visited, index) == true) return true;

        index -= 1;
    }

    return false;
}

int main() {
    vector<int> elems = {7, 3, 2, 3, 5, 1, 2};
    int k = 4;
    int auxSum = 5;
    int index = 0;
    vector<int> visited(elems.size(), 0);
    vector<int> subSets(k, 0);

    cout << boolalpha << partitionKEqualSum(elems, subSets, auxSum, visited, index);

    return 0;
}