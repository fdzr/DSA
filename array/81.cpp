//
// Created by fzamora on 30-01-23.
//
#include "bits/stdc++.h"

using namespace std;

vector<double> convertTemperature(double celsius) {
    return {celsius + 273.15, celsius * 1.80 + 32.00};
}

int main() {
    float celsius = 36.50;
    cout<<convertTemperature(celsius)[0]<< " "<<convertTemperature(celsius)[1];

    return 0;
}