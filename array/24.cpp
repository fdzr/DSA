#include <bits/stdc++.h>
#include "../common/array.h"

using namespace std;
using namespace ARRAY;

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> ans;
    int size = nums.size();
    int cont = 0;
    for(int i=0;i<size;++i) {
        for(int j=0;j< size;++j)
            if(j != i && nums[j] < nums[i])
                cont++;
        
        ans.push_back(cont);
        cont = 0;
    }
    
    return ans;
}

int main() {
    vector<int> vc = {8,1,2,2,3}, ans;
    ans = smallerNumbersThanCurrent(vc);
    cout<<ans;

    return 0;
}