//
// Created by fzamora on 05-01-23.
//

#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vvi helper() {
    vvi aux({{1}, {1,1}});
    vi tmp;

    for(int i = 1; i < 29; ++i) {
        tmp.clear();
        tmp.push_back(1);
        for(int j = 0; j < aux[i].size() - 1; ++j) {
            tmp.push_back(aux[i][j] + aux[i][j+1]);
        }
        tmp.push_back(1);
        aux.push_back(tmp);
    }
    return aux;
}

vvi generate(int numRows) {
    vvi ans;
    vvi aux = helper();
    copy(aux.begin(), aux.begin() + numRows, back_inserter(ans));

    return ans;
}

int main() {
    for(auto v: generate(1)) {
        for(auto elem: v)
            cout<<elem<<" ";
        cout<<endl;
    }


    return 0;
}
