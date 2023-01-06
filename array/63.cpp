//
// Created by fzamora on 06-01-23.
//

#include "bits/stdc++.h"

using namespace std;

bool divisorGame(int n) {
    return n % 2 == 0;
}


int main() {
    int n = 10;
    cout<<divisorGame(n);

    return 0;
}