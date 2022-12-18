#include <bits/stdc++.h>

using namespace std;


int minSteps(string s, string t) {
    vector<int> ans (26, 0);
    int cont = 0;
    for(int i = 0; i < s.size(); ++i) {
        ans[s[i] - 'a']++;
        ans[t[i] - 'a']--;
    }

    for_each(ans.begin(), ans.end(), [&cont](int e){
        cont += (e < 0)? e:0;
    });

    return abs(cont);
}



int main() {
    string s = "bab";
    string t = "aba";

    cout<<minSteps(s, t);
    
    return 0;
}