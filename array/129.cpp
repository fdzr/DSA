#include <bits/stdc++.h>

using namespace std;

using pi = pair<int, int>;

int minSetSize(vector<int>& arr) {
    unordered_map<int, int> um;
    set<pair<int, int>, function<bool(const pi &,const pi&)>> l([](const pi &a,const pi &b){
        if(a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    });

    int cont = 0;
    int cantKeysProccessed = 0;
    int n = arr.size();

    for(auto num: arr)
        um[num]++;

    l.insert(um.begin(), um.end());

    for(auto ptr: l) {
        cantKeysProccessed++;
        cont += ptr.second;

        if(n - cont <= int(n / 2))
            break;
    }

    return cantKeysProccessed;
}


int main() {
    vector<int> v {1,2,2,2,3,3,4,4,5};
    cout<<minSetSize(v);

    return 0;
}