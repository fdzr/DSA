#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> vc = {4,1,2,1,2};
    int ans = vc[0];

    for(int i=1;i<vc.size();++i)
        ans ^= vc[i];

    cout<<ans;

    return 0;
}