//
// Created by fzamora on 18-05-23.
//
#include <bits/stdc++.h>

using namespace std;

int wateringPlants(vector<int>& plants, int capacity) {
    int copyCapacity = capacity;
    int steps = 0;

    for(int i = 0; i < plants.size(); ++i) {
        if (copyCapacity >= plants[i]) {
            copyCapacity -= plants[i];
            steps += 1;
        }
        else {
            steps += i;
            steps += (i + 1);
            copyCapacity = capacity;
            copyCapacity -= plants[i];
        }
    }
    return steps;
}

int main() {
    vector<int> plants = {7,7,7,7,7,7,7};
    int capacity = 8;
    cout<<wateringPlants(plants, capacity);

    return 0;
}