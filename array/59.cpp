#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

int helper(int num) {
    int cont = 0;
    while(num) {
        cont += num & 1;
        num = num >> 1;
    }

    return cont;
}

vi countBits(int n) {
    vi ans(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        ans[i] = helper(i);
    }

    return ans;
}


int main () {
    int n = 5;
    for(auto elem: countBits(n))
        cout<<elem<<" ";
    
}