#include <bits/stdc++.h>

using namespace std;

using vvs = vector<vector<string>>;
using um = unordered_map<string, string>;
pair<bool, string> find(vvs k, string key) {
    for(auto v: k) {
        if(v[0] == key)
            return {true, v[1]};
    }

    return {false, "?"};
}

unordered_map<string, string> loadCache(vvs k) {
    unordered_map<string, string> cache;
    for(auto v: k) {
        cache[v[0]] = v[1];
    }

    return cache;
}

string evaluate(string s, vector<vector<string>>& knowledge) {
    string ans = "";
    string key = "";
    um cache = loadCache(knowledge);


    for(int i = 0; i < s.size();) {
        if(s[i] != '(' && s[i] != ')') {
            ans += s[i];
            ++i;
        }
        else {
            
            while(s[++i] != ')') {
                key += s[i];
            }
            ++i;

            ans += cache[key] != "" ? cache[key] : "?";
            key = "";
        }
    }

    return ans;
}

int main() {
    string s = "hi(name)";
    vvs knowledge = {{"a", "b"}};
    cout<<evaluate(s, knowledge);


    return 0;
}