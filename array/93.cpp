#include <bits/stdc++.h>

using namespace std;

int lastStoneWeight(vector<int>& stones) {
    if(stones.size() == 1)
        return stones[0];

    sort(stones.begin(), stones.end());
    int n = stones.size();
    while(stones[n - 2] != 0) {
        if(stones[n - 2] == stones[n - 1])
            stones[n - 2] = 0, stones[n - 1] = 0;
        else {
            int temp = stones[n - 2];
            stones[n - 2] = 0;
            stones[n - 1] -= temp;
        }
        
        sort(stones.begin(), stones.end());
    }

    return stones[n - 1];
}

using vi = vector<int>;
int main () {
    vi stones = {1,1,1,1,1,1,1,1};
    cout<<lastStoneWeight(stones);

    return 0;
}