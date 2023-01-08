#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

vi helper() {
    vi ans(46, 0);
    ans[0] = 1;
    ans[1] = 1;
    for(int i = 2; i < 46; ++i)
        ans[i] = ans[i-2] + ans[i-1];

    return ans;
}

int climbStairs(int n) { 
    vi ans = helper();
    return ans[n];
}



int main() {
    int n = 45;
    cout<<climbStairs(n);


    return 0;
}