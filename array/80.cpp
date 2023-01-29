#include <bits/stdc++.h>

using namespace std;

vector<int> finalPrices(vector<int>& prices) {
    vector<int> finalPrices = prices;
    for(int i = 0; i < prices.size() - 1; ++i) {
        for(int j = i+1; j < prices.size(); ++j) {
            if(prices[j] <= prices[i]) {
                finalPrices[i] -= prices[j];
                break;
            }
        }
    }
    return finalPrices;
}

int main() {
    vector<int> prices = {10,1,1,6};
    for(auto elem: finalPrices(prices))
        cout<<elem<<" ";

    return 0;
}