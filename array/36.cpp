#include <bits/stdc++.h>

using namespace std;


int maxProductDifference(vector<int>& nums) {
    int min_1 = INT_MAX, min_2 = INT_MAX;
    int max_1 = INT_MIN, max_2 = INT_MIN;

    for(auto num: nums) {
        if(num >= max_1) {
            max_2 = max_1;
            max_1 = num;
        }
        if(num > max_2 && num < max_1)    
            max_2 = num;

        if(num <= min_1) {
            min_2 = min_1;
            min_1 = num;
        }
        if(num < min_2 && num > min_1)
            min_2 = num;
    }
    if(max_1 == INT_MIN)
        max_1 = max_2;
    if(max_2 == INT_MIN)
        max_2 = max_1;

    if(min_1 == INT_MAX)
        min_1 = min_2;
    if(min_2 == INT_MAX)
        min_2 = min_1;

    return (max_1 * max_2) - (min_2 * min_1);

}


int main() {
    vector<int> v = {2,9,5,9,1};
    cout<<maxProductDifference(v);


    return 0;
}