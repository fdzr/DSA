//
// Created by fzamora on 28-12-22.
//

#include "bits/stdc++.h"

using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    vector<int> ans(2002, 0);
    set<int> s;
    bool flag = false;
    int prev;

    for(auto num: arr) {
        if(num < 0) {
            ans[abs(num) + 1000]++;
        }
        else
            ans[num]++;
    }

    for(auto elem: ans) {
        if(elem != 0) {
            auto it = s.insert(elem);
            if(!it.second)
                return false;
        }
    }
    return true;
}


int main() {
    vector<int> arr = {26,2,16,16,5,5,26,2,5,20,20,5,2,20,2,2,20,2,16,20,16,17,16,2,16,20,26,16};
    cout<<uniqueOccurrences(arr);

    return 0;
}