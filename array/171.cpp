#include <bits/stdc++.h>

using namespace std;

int distributeCandies(vector<int>& candyType) {
    vector<int> ans(200001, 0);
    int n = candyType.size();

    for(int i = 0; i < candyType.size(); ++i) {
        if (candyType[i] >= 0)
            ans[candyType[i]] += 1;
        else
            ans[abs(candyType[i]) + 10000] += 1;
    }

    int cont = 0;
    for(int i =0;i < ans.size(); ++i)
        cont += (ans[i] >= 1);


    return min(n / 2, cont);
}

int main() {
    vector<int> candyType = {100000,0,100000,0,100000,0,100000,0,100000,0,100000,0};
    cout<<distributeCandies(candyType);

    return 0;
}