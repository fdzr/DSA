#include <bits/stdc++.h>

using namespace std;

string restoreString(string s, vector<int>& indices) {
    string ans(indices.size(), '-');
    for(int i=0;i<indices.size();++i)
        ans[indices[i]] = s[i];

    return ans;
}

int main() {
    vector<int> vc = {4,5,6,7,0,2,1,3};
    string cad = "codeleet";
    cout<<restoreString(cad, vc);


    return 0;
}