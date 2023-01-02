#include <bits/stdc++.h>

using namespace std;

using ums = unordered_map<string, string>;

string destCity(vector<vector<string>>& paths) {
    ums um;
    string ans = "";
    for(auto dest: paths)
        um[dest[0]] = dest[1];

    for(auto dest: paths) {
        if(um.find(dest[1]) == um.end()) {
            ans = dest[1];
            break;
        }

    }
    return ans;
}

int main() {
    vector<vector<string>> dest = {{"A","Z"}};
    cout<<destCity(dest);

    return 0;
}