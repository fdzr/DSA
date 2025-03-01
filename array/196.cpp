#include <bits/stdc++.h>

using namespace std;

ostream& operator<<(ostream& out, const vector<int>& collection) {
    for (const int& e : collection) {
        printf("%d ", e);
    }

    return out;
}

vector<int> applyOperations(vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; ++i) {
        if (nums[i] == nums[i + 1]) {
            nums[i] *= 2;
            nums[i + 1] = 0;
        }
    }

    cout << nums;
    cout << "\n";

    int L = 0, R = 1;

    while (R < nums.size()) {
        if (nums[L] != 0) {
            ++L;
            R = L + 1;
            continue;
        }
        if (nums[R] != 0) {
            swap(nums[L], nums[R]);
            ++R;
            ++L;
        } else {
            ++R;
        }

    }

    return nums;
}

int main() {
    vector<int> nums = {0, 1, 1, 1, 2, 2, 3, 3, 4, 4, 11, 12, 12};

    applyOperations(nums);

    for (int e : nums) {
        printf("%d ", e);
    }

    return 0;
}