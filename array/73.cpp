#include <bits/stdc++.h>

using namespace std;


int minimumCost(vector<int>& cost) {
    sort(cost.begin(), cost.end(), greater<int>());
    int cont = 0;
    int ans = 0;

    for(int i = 0; i < cost.size(); ++i) {
        cont++;
        if(cont == 3) {
            cont = 0;
            continue;
        }
        ans += cost[i];
    }

    return ans;
}

int main() {
    vector<int> cost = {1};
    cout<<minimumCost(cost);

    return 0;
}