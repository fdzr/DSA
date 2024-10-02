#include <bits/stdc++.h>

using namespace std;


int firstUniqChar(string s) {
    vector<pair<int, int>> stat(26, {0, 0});

    for(int i = 0; i < s.size(); ++i) {
        stat[s[i] - 'a'].first = i;
        stat[s[i] - 'a'].second++;
    }

    int index = INT_MAX;
    for(int i = 0; i < stat.size(); ++i) {
        if(stat[i].second == 1 && stat[i].first < index)
            index = stat[i].first;
    }

    return index == INT_MAX? -1: index;

}

int main() {
    string s = "aabb";
    cout<<firstUniqChar(s);
    

    return 0;
}