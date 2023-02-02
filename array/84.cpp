//
// Created by fzamora on 02-02-23.
//
#include "bits/stdc++.h"

using namespace std;

int sumDigits(int number) {
    int sum = 0;
    while(number) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int countBalls(int lowLimit, int highLimit) {
    vector<int> ans(46);
    for(int i = lowLimit; i <=highLimit ; ++i)
        ans[sumDigits(i)]++;

    return *max_element(ans.begin(), ans.end());
}

int main() {
    int l = 19;
    int h = 28;
    cout<<countBalls(l, h);

    return 0;
}