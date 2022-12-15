#include <bits/stdc++.h>

using namespace std;

bool checkIfPangram(string sentence) {
    vector<int> ans(26, 0);
    for(auto ch: sentence)
        ans[ch - 'a']++;

    auto it = find_if(ans.begin(), ans.end(), [](int e){
        return e == 0;
    });

    return (it == ans.end())?true:false;
}


int main() {
    string sentence = "leetcode";
    cout<<checkIfPangram(sentence);


    return 0;
}