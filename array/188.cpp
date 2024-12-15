#include <bits/stdc++.h>

using namespace std;

class Item {
   public:
    int value;
    int index;
    int indexOfList;

    Item() = default;
    Item(int v, int i, int iol) : value{v}, index{i}, indexOfList{iol} {}

    // bool operator<(const Item& other) const { return this->value < other.value; }
    bool operator>(const Item& other) const { return this->value > other.value; }
};

using vvi = vector<vector<int>>;

/*
k -> average values in lists
n - > size of list of lists
O (k * k * n)

*/

vector<int> mergeKSortedList(vvi lists) {
    vector<int> answer(lists.size() * lists[0].size());
    vector<int> indexes(lists.size());

    for (int i = 0; i < lists.size(); ++i) {
        indexes[i] = lists[i].size() - 1;
    }

    for (int i = answer.size() - 1; i >= 0; --i) {
        int index = -1;
        int maxElement = INT_MIN;
        for (int j = 0; j < indexes.size(); ++j) {
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

/*
k -> average values in lists
n -> size of list of lists
O (k * n * log(k))

*/

vector<int> mergeKSortedList2(const vvi& lists) {
    int k = 0;
    int j = -1;
    for (int i = 0; i < lists.size(); ++i) k += lists[i].size();

    vector<int> answer(k, 0);

    priority_queue<Item, vector<Item>, greater<Item>> pq;

    for (int i = 0; i < lists.size(); ++i) {
        pq.push(Item(lists[i][0], 0, i));
    }

    while (!pq.empty()) {
        Item item = pq.top();
        pq.pop();

        if (item.index < lists[item.indexOfList].size()) {
            ++j;
            pq.push(
                Item(
                    lists[item.indexOfList][item.index + 1], 
                    item.index + 1,
                    item.indexOfList
                )
            );
            answer[j] = item.value;
        }
    }

    return answer;
}

int main() {
    vvi lists = {{10, 20, 30, 40},
                 {15, 25, 35, 45},
                 {27, 29, 37, 48},
                 {32, 33, 39, 50},
                 {16, 18, 22, 28}};

    for (int e : mergeKSortedList2(lists)) cout << e << " ";

    return 0;
}