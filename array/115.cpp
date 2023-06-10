#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
void reverse_(vi &nums, int initial, int final) {
    if (initial >= final)
        return;
    
    swap(nums[initial], nums[final]);
    reverse_(nums, ++initial, --final);
}

void rotate(vector<int>& nums, int k) {
    k = k % nums.size();
    ::reverse_(nums, 0, nums.size() - 1);
    ::reverse_(nums, 0, k - 1);
    ::reverse_(nums, k, nums.size() - 1);
}

int main() {
    vi a = {-1};
    rotate(a, 2);

    for(auto e: a)
        cout<<e<<" ";

    return 0;
}