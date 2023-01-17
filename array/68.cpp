//
// Created by fzamora on 17-01-23.
//
#include "bits/stdc++.h"

using namespace std;

using vi = vector<int>;

vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    sort(nums.begin(), nums.end());
    int cont = 0;
    int sum = 0;
    bool flag = false;
    vi ans(queries.size());

    for(int i = 0; i < queries.size(); ++i){
        for(int num : nums) {
            if((sum + num) > queries[i]) {
                ans[i] = cont;
                cont = 0;
                sum = 0;
                flag = true;
                break;
            }
            else {
                sum += num;
                cont++;
            }
        }
        if(!flag) {
            ans[i] = cont;
            cont = 0;
            sum = 0;
        }
        flag = false;
    }
    return ans;
}

vector<int> answerQueries2(vector<int>& nums, vector<int>& queries) {
    sort(nums.begin(), nums.end());
    for(int i = 1; i < nums.size(); ++i)
        nums[i] += nums[i-1];

    int cont = 0;
    vi ans(queries.size());
    for(int i = 0; i < queries.size(); ++i) {
        auto ptrIndex = lower_bound(nums.begin(),nums.end(), queries[i]);
        int index = ptrIndex - nums.begin();
        ans[i] = (nums[index] == queries[i])? index+1: index;
    }
    return ans;
}

int main() {
    vi nums = {4,5,2,1};
    vi queries = {3,10,21};
    for(auto elem: answerQueries2(nums, queries))
        cout<<elem<<" ";

    return 0;
}