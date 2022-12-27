#include <bits/stdc++.h>

using namespace std;

bool isNotBanned(vector<string> banned, string query){
    for(auto str: banned)
        if(str == query)
            return false;

    return true;
}

string mostCommonWord(string paragraph, vector<string>& banned) {
    stringstream ss(paragraph);
    string input;
    unordered_map<string, int> um;
    int max = 0;
    string ans;

    while(ss>>input) {
        transform(
            input.begin(), 
            input.end(), 
            input.begin(), 
            [](char c)
            {
                return tolower(c);
            }
        );
        if(!isalpha(input.back()))
            input = input.substr(0, input.size()-1);

        for(int j = 0; j < input.size(); ++j){
            if(
                input[j] == '.'|| input[j] == ';' || input[j] == '!' 
                || input[j] == '?' ||input[j] == '.' || input[j] == '\'' || input[j] == ','
            ) {
                input[j] = '+';                
            }
        }

        int index = input.find('+');
        bool flag = false;
        while(index != string::npos) {
            string c = input.substr(0, index);
            input = input.substr(index + 1);
            um[c]++;
            flag = true;
            index = input.find('+');
        }

        if(flag && input != "")
            um[input]++;

        
        if(!flag)
            um[input]++;
    }

    for(auto & [k, v]: um) {
        if(v > max && isNotBanned(banned, k)){
            max = v;
            ans = k;
        }

    }
    return ans;
    
}

int main() {
    string p = "a.";
    vector<string> banned = {""};
    cout<<mostCommonWord(p, banned);

    return 0;
}