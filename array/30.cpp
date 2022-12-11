#include <bits/stdc++.h>

using namespace std;

int arithmeticTriplets(vector<int>& nums, int diff) {
    int cont = 0;
    for(int i=0;i<nums.size()-2; ++i)
        for(int j=i+1;j<nums.size()-1; ++j)
            for(int k=j+1;k<nums.size();++k)
                if(nums[j] - nums[i] == diff && nums[k] - nums[j] == diff)
                    cont++;

    return cont;
          
}


int main() {
    vector<int> v = {0,1,4,6,7,10};
    int diff = 3;
    cout<<arithmeticTriplets(v, diff);


    return 0;
}