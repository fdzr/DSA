#include <bits/stdc++.h>
#include "../common/array.h"

using namespace std;
using namespace ARRAY;

int finalValueAfterOperations(vector<string>& operations) {
    unordered_map<string, int> um = {
        {"X++", 1},
        {"++X", 1},
        {"--X", -1},
        {"X--", -1},
    };

    int sum = 0;
    for(auto op: operations)
        sum+= um[op];
    
    return sum;
}

int main() {
    vector<string> vc = {"X++", "++X", "--X", "X--"};
    cout<<finalValueAfterOperations(vc);

    return 0;
}