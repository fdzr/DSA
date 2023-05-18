#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
vector<int> rearrangeArray(vi& nums) {
    vi answer(nums.size());
    int indexPositive = 0;
    int indexNegative = 1;
    for(auto elem: nums) {
        if(elem >= 0) {
            answer[indexPositive] = elem;
            indexPositive += 2;
        }
        else {
            answer[indexNegative] = elem;
            indexNegative += 2;
        }
    }

    return answer;
}

int main () {
    vi nums = {-1, -2,-3,-4, 1,2,3,4,-5,5};
    vi answer = rearrangeArray(nums);

    for(auto elem: answer)
        cout<<elem<<" ";

    return 0;
}