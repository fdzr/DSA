#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if(a == 0)
        return b;
    if(b == 0)
        return a;

    if(a == b)
        return a;
    
    if(a > b)
        return gcd(a-b, b);
    else 
        return gcd(a, b-a);

}

int findGCD(vector<int>& nums) {
    int min = INT_MAX;
    int max = INT_MIN;
    for(auto elem: nums) {
        if(elem < min)
            min = elem;
        if(elem > max)
            max = elem;
    }

    return gcd(max, min);
}

int main() {
    vector<int> nums = {3,3};
    cout<<findGCD(nums);

    return 0;
}