#include <bits/stdc++.h>

using namespace std;


vector<int> sumZero(int n) {
    int m = n/2;
    vector<int> ans;

    for(int i =1; i <= m; ++i) {
        ans.push_back(i);
        ans.push_back(-1*i);
    }

    if(ans.size() == n - 1)
        ans.push_back(0);


    return ans;
}

int main() {
    int n = 1;
    for(auto e: sumZero(n))
        cout<<e<<" ";

    return 0;
}