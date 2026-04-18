#include <bits/stdc++.h>

using namespace std;

int mirrorDistance(int n) {
    string aux = to_string(n);
    reverse(aux.begin(), aux.end());

    return abs(n - stoll(aux));
}

int main() {
    int n = 7;
    cout << mirrorDistance(n);

    return 0;
}