#include <bits/stdc++.h>

using namespace std;

string truncateSentence(string s, int k) {
    istringstream ss(s);
    string ans = "";
    string in;

    while(ss>>in && k--) {
        ans +=in;
        ans += " ";
    }
    ans.pop_back();
    return ans;
}

int main() {
    string sentence = "chopper is not a tanuki";
    cout<<truncateSentence(sentence, 5);

    return 0;
}