#include <bits/stdc++.h>

using namespace std;

int thirdMax(vector<int>& nums) {
    int max_1 = INT_MIN;
    int max_2 = INT_MIN;
    int max_3 = INT_MIN;
    bool flag = false;

    for(auto e: nums) {
        if(e == INT_MIN)
            flag = true;
        if(e >= max_1) {
            if(e > max_1) {
                max_3 = max_2;
                max_2 = max_1;
                max_1 = e;
            }
        }
        if(e >= max_2 && e < max_1) {
            if(e > max_2) {
                max_3 = max_2;
                max_2 = e;
            }
        }
        if(e >= max_3 && e <= max_2 && e < max_1) {
            if(e > max_3 && e < max_2) {
                max_3 = e;
            }
        }
    }
    if(max_3 != INT_MIN)
        return max_3;
    if(max_3 == INT_MIN && max_2 == INT_MIN)
        return max_1;
    if (max_3 == INT_MIN && max_2 != INT_MIN) {
        if(flag)
            return INT_MIN;
        return max_1; 
    }

        
    
    return max_3;
}


int main() {
    vector<int> nums = {1, 2,3};
    int ans = thirdMax(nums);;
    cout<<ans;
    

    return 0;
}