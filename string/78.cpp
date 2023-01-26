#include <bits/stdc++.h>

using namespace std;

bool digitCount(string num) {
    unordered_map<int, int> um;
    for(auto digit: num)
        um[digit - 48]++;

    for(int i =0; i < num.size(); ++i)
        if(num[i] - 48 != um[i])
            return false;

    return true;
}

int main() {
    string num = "10";
    cout<<digitCount(num);


    return 0;
}