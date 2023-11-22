#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
vector<vector<int>> findMatrix(vector<int>& nums) {
    vi tmp;
    vvi ans;
    bool flag = false;

    for(auto a: nums) {
        for(auto &vec: ans) {
            auto it = find(vec.begin(), vec.end(), a);
            if(it == vec.end()) {
                vec.push_back(a);
                flag = true;
                break;
            }
        }
        
        if(!flag){
            auto it = find(tmp.begin(), tmp.end(), a);
            if(it != tmp.end()) {
                ans.push_back(tmp);
                tmp.clear();
                tmp.push_back(a);
            } 
            else
                tmp.push_back(a);

        
        }
        else
            flag = false;
    }

    if(!tmp.empty())
        ans.push_back(tmp);

    tmp.clear();

    return ans;
}

int main() {
    vi nums = {1,3,4,1,2,3,1,4,5,6,4,3,2,3,4,5,6,1,2,3,4,5,6,21,7,8};

    for(auto vec: findMatrix(nums)) {
        for(auto e: vec)
            cout<<e<<" ";
        cout<<endl;
    }
        


    return 0;
}