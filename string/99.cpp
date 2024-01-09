#include <bits/stdc++.h>

using namespace std;

vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
    
    vector<string> ans;

    for(auto w: words) {
        bool flag = false;
        unordered_map<char, char> a, b;

        for(int i = 0; i < w.size(); ++i) {
            assert(pattern.size() == w.size());

            if(a[w[i]] != a[b[pattern[i]]]) {
                flag = true;
                break;
            } else {
                a[w[i]] = pattern[i];
                b[pattern[i]] = w[i];
            }
        }

        if(!flag)
            ans.push_back(w);
    }

    return ans;

}

int main() {
    vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
    string pattern = "abb";

    for(auto word: findAndReplacePattern(words, pattern))
        cout<<word<<endl;

    return 0;
}