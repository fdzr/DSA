//
// Created by fzamora on 05-01-23.
//
#include "bits/stdc++.h"

using namespace std;

using vi = vector<int>;

vi helper(int n) {
    vi ans(31);
    ans[0] = 0, ans[1] = 1;
    for(int i = 2; i <= n; ++i)
        ans[i] = ans[i-2] + ans[i-1];

    return ans;
}

int fib(int n) {
    vi ans = helper(30);
    return ans[n];
}

int main() {
    int n = 30;
    cout<<fib(n);

    return 0;
}