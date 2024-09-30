#include <bits/stdc++.h>

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    bool mark = false;
    int index = 0;

    for(; index < flowerbed.size(); ) {
        if (flowerbed[index] == 1) {
            index += 2;
            continue;
        }
        if (index + 1 < flowerbed.size() && flowerbed[index] == 0 && flowerbed[index + 1] == 0) {
            --n;
            index += 2;
            continue;
        }
        if (index + 1 >= flowerbed.size() && flowerbed[index] == 0) {
            --n;
            break;
        }
        if (flowerbed[index + 1] == 1) {
            index += 3;
            continue;
        }
    }

    return n <= 0;
}

int main() {
    int n = 1;
    vector<int> flowerbed = {0,0,1,0,0};
    cout<<boolalpha<<canPlaceFlowers(flowerbed, n);


    return 0;
}