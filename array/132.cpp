#include <bits/stdc++.h>

using namespace std;

using pi = pair<int, int>;
using vvi = vector<vector<int>>;
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    auto cmp = [](const pi &a, const pi &b){
        double distA = sqrt(pow(a.first - 0, 2) + pow(a.second - 0, 2));
        double distB = sqrt(pow(b.first - 0, 2) + pow(b.second - 0, 2));

        return distA > distB;
    };

    vvi ans;
    priority_queue<pi, vector<pi>, decltype(cmp)> pq(cmp);
    
    for(auto item:points)
        pq.push(make_pair(item[0], item[1]));

    while(k--) {
        ans.push_back({pq.top().first, pq.top().second});
        pq.pop();
    }

    return ans;
}

ostream& operator<<(ostream& out, vector<int> v) {
    out<<"["<<v.front()<<" "<<v.back()<<"]";
    return out;
}

int main() {
    vvi points = {{1, 3}, {-2, 2}};
    int k = 1;
    for(auto v: kClosest(points, k))
        cout<<v<<endl;


    return 0;
}