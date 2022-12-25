#include <bits/stdc++.h>

using namespace std;


vector<int> numberOfPairs(vector<int>& nums) {
    unordered_map<int, int> um;
    int cont = 0;

    for(auto elem: nums) {
        um[elem]++;
        if(um[elem] == 2) {
            um.erase(elem);
            cont++;
        }
    }

    return {cont, static_cast<int>(um.size())};        
}


int main() {
    vector<int> nums = {0};
    for(auto elem: numberOfPairs(nums))
        cout<<elem<<" ";


    return 0;
}