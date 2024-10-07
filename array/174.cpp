#include <bits/stdc++.h>

using namespace std;

bool isBadVersion(int) {}

int firstBadVersion(int n) {
    int L = 0;
    int R = n;

    while(L <= R) {
        int M = L + (R - L) / 2;

        if(isBadVersion(M))
            R = M - 1;
        else
            L = M + 1;
    }

    return L;
}

int main() {
    

    return 0;
}