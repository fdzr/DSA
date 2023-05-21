#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
int triangularSum(vector<int>& nums) {
    vi temp = nums;
    vi aux;

    while(temp.size() != 1) {
        for(int i = 1; i < temp.size(); ++i) {
            aux.push_back((temp[i] + temp[i-1]) % 10);
        }
        temp = aux;
        aux.clear();
    }

    return temp.front();   
}

int main() {
    vi nums = {5};
    cout<<triangularSum(nums);

    return 0;
}