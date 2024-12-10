#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

void next_permutation(vector<int> &nums) {
    int largestIndex = -1;
    bool valid = false;

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] > nums[i - 1] && i > largestIndex) {
            largestIndex = i;
            valid = true;
        }
    }

    if (valid == false) {
        reverse(nums.begin(), nums.end());
        return;
    }

    int largestSecondIndex;
    for (int j = largestIndex; j < nums.size(); ++j) {
        if (nums[j] > nums[largestIndex - 1]) largestSecondIndex = j;
    }

    swap(nums[largestSecondIndex], nums[largestIndex - 1]);

    reverse(nums.begin() + largestIndex, nums.end());
}

int main() {
    // vi nums = {0, 1, 2, 5, 3, 3, 0};
    vi nums = {1, 2, 3, 4, 5};
    for (int e : nums) cout << e << " ";

    cout << "\n";

    ::next_permutation(nums);

    for (int e : nums) cout << e << " ";

    return 0;
}