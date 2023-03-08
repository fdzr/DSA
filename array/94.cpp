#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;

vvi sortTheStudents(vvi& score, int k) {
    vvi answer;
    vector<pair<int, int>> index;
    for (int i = 0; i < score.size(); ++i)
        index.push_back({score[i][k], i});

    sort(index.begin(), index.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    });

    for(auto item: index) 
        answer.push_back(score[item.second]);

    return answer;
}

int main () {
    vvi score = {{3, 4}};
    int k = 0;

    vvi ans = sortTheStudents(score, k);
    for(auto rows: ans){
        for(auto elem: rows)
            cout<<elem<<" ";
        cout<<endl;
    }


    return 0;
}