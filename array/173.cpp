#include <bits/stdc++.h>

using namespace std;

bool isPerfectSquare(int num) {
    if(num == 1 || num == 2)
        return true;

    int L = 0;
    int R = num / 2;

    while(L <= R) {
        int M = L + (R - L) / 2;

        if(M * M == num)
            return true;
        else if(M * M < num)
            L = M + 1;
        else 
            R = M - 1;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout<<boolalpha<<isPerfectSquare(2147483647);

    return 0;
}