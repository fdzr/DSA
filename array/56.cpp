//
// Created by fzamora on 28-12-22.
//

#include "bits/stdc++.h"

using namespace std;

bool canBeEqual(vector<int>& target, vector<int>& arr) {
    vector<int> ans (1001, 0);
    for(int i = 0; i < target.size(); ++i) {
        ans[target[i]]++;
        ans[arr[i]]--;
    }
    for(auto elem: ans)
        if(elem != 0)
            return false;

    return true;
}


int main() {
    vector<int> target = {3, 7, 9};
    vector<int> arr = {3, 7, 11};
    cout<<canBeEqual(target, arr);

    return 0;
}