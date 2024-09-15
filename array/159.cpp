#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
vi findDisappearedNumbers(vi& nums) {
    vi res;

    for(int i = 0; i < nums.size(); ++i) {
        int temp = nums[i] - 1;
        while (temp >= 0) {
            int aux = nums[temp];
            if (aux == -1)
                break;

            nums[temp] = -1;
            temp = aux -1;
        }
    }

    for(int i = 0; i < nums.size(); ++i) {
        if (nums[i] != -1)
            res.push_back(i + 1);
    }

    return res;
}

int main() {
    vi nums = {1,2,3,3,5,6};
    for(auto &value: findDisappearedNumbers(nums))
        cout<<value<<" ";

    return 0;
}