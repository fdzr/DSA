#include <bits/stdc++.h>

using namespace std;

int numIdenticalPairs(vector<int>& nums) {
    int n = nums.size(), cont = 0;
    for(int i=0;i<n-1;++i)
        for(int j = i+1;j<n;++j)
            if(i < j && nums[i] == nums[j])
                cont++;

    return cont;
}

int main() {
    vector<int> vc = {1,1,1,1};
    cout<<numIdenticalPairs(vc);

    return 0;
}