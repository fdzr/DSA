#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

int getMaximumGenerated(int n) {
    vi ans(n + 1, 0);
    int maxElement = INT_MIN;
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    ans[0] = 0;
    ans[1] = 1;
    for(int i = 2; i < n + 1; ++i) {
        if(i % 2)
            ans[i] = ans[i/2] + ans[(i/2) + 1];
        else
            ans[i] = ans[i/2];

        maxElement = max(maxElement, ans[i]);
    }

    return maxElement;
}

int main() {
    int n = 100;
    cout<<getMaximumGenerated(n);
    
    return 0;
}