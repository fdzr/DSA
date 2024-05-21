#include <bits/stdc++.h>

using namespace std;

int maxIceCream(vector<int>& costs, int coins) {
    sort(costs.begin(), costs.end());
    int sum = 0;
    int cont = 0;

    for(auto c: costs) {
        sum += c;
        if (sum <= coins)
            cont++;
        else
            break;
    }        

    return cont;
}

int main() {
    vector<int> costs {1,6,3,1,2,5};
    cout<<maxIceCream(costs, 20);

    return 0;
}