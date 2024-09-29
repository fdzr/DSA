#include <bits/stdc++.h>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end(), greater<int>());
    sort(s.begin(), s.end(), greater<int>());

    int indexSize = 0;
    int output = 0;
    for(int i = 0; i < g.size(); ++i) {
        if(indexSize >= s.size())
            break;
        if(g[i] <= s[indexSize]) {
            ++output;
            ++indexSize;
        }
    }

    return output;

}

int main() {
    vector<int> g = {1, 2};
    vector<int> s = {1, 2, 3};
    cout<<findContentChildren(g, s);

    return 0;
}