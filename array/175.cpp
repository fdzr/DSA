#include <bits/stdc++.h>

using namespace std;

int arrangeCoins(int n) {
    return static_cast<int>((-1 + static_cast<long long int>(sqrt(1 + 8LL*n))) / 2);
}


int main() {
    int n = 1804289383;
    cout<<arrangeCoins(n);

    return 0;
}