#include <bits/stdc++.h>

using namespace std;

bool isArraySpecial(vector<int> &nums)
{
    int lastParity = nums[0] % 2;

    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] % 2 == lastParity)
            return false;

        lastParity = nums[i] % 2;
    }

    return true;
}

int main()
{
    vector<int> nums = {4, 3, 1, 6};
    cout << boolalpha << isArraySpecial(nums);

    return 0;
}
