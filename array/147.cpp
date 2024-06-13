#include <bits/stdc++.h>

using namespace std;

bool canJump(vector<int> &nums)
{
    int maxJump = 0;

    for (int i = 0; i < nums.size() - 1; ++i)
    {
        if (maxJump < i)
            return false;
        maxJump = max(maxJump, nums[i] + i);
    }

    return maxJump >= nums.size() - 1;
}

int main()
{
    vector<int> nums = {0, 2, 3};
    cout << boolalpha << canJump(nums);

    return 0;
}