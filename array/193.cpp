#include <bits/stdc++.h>

using namespace std;

struct Item {
    int freq;
    int value;
    int index;

    Item(int f, int v, int i) {
        freq = f;
        value = v;
        index = i;
    }

    bool operator>(const Item& other) const {
        if (freq == other.freq) return index <= other.index;

        return freq < other.freq;
    }

    bool operator<(const Item& other) const {
        if (freq == other.freq) return index <= other.index;

        return freq > other.freq;
    }
};

using pi = pair<int, int>;
vector<int> sortElementsByFrequencyAndIndexes(vector<int>& nums) {
    vector<int> answer;
    unordered_map<int, pi> um;

    for (int i = 0; i < nums.size(); ++i) {
        auto it = um.find(nums[i]);
        if (it == um.end()) {
            um[nums[i]] = {1, i};
        } else {
            pi p;
            p.first = it->second.first + 1;
            p.second = min(i, it->second.second);
            um[nums[i]] = p;
        }
    }

    vector<Item> newElements;
    for (const auto& item : um) {
        newElements.push_back(Item(item.second.first, item.first, item.second.second));
    }

    sort(newElements.begin(), newElements.end());

    // for_each(newElements.begin(), newElements.end(), [&](const Item& item) {
    //     answer.insert(answer.end(), item.freq, item.value);
    // });

    for(const auto& elem: newElements)
        fill_n(back_inserter(answer), elem.freq, elem.value);


    return answer;
}

int main() {
    vector<int> nums = {3, 3, 1, 1, 1, 8, 3, 6, 8, 7, 8};
    for (const auto& elem : sortElementsByFrequencyAndIndexes(nums)) cout << elem << " ";
    cout << "\n";

    return 0;
}