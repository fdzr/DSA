#include <bits/stdc++.h>

using namespace std;

int findNumbers(vector<int>& nums) {
    int cont = 0;
    for(auto num: nums){
        if(to_string(num).size() % 2 == 0)
            cont++;
    }
    return cont;
}


int main() {
    vector<int> nums = {12,345,2,6,7896};
    cout<<findNumbers(nums);

    return 0;
}