#include <bits/stdc++.h>

using namespace std;

constexpr int conversion = 32;

void debug(const unordered_map<char, int> &um) {
    for(const auto& [k, v]: um) {
        cout<< k << " "<< v <<"\n";
    }

}

int numberOfSpecialChars(string word) {
    unordered_map<char, int> um;

    for (const char& ch : word) {
        if (islower(ch)) {
            if (um[ch - conversion] == 0) {
                um[ch] = 1;
            } else {
                um[ch] = 0;
            }
        } else {
            um[ch]++;
        }
    }

    int answer = 0;
    for (const auto& [ch, cont] : um) {
        if (islower(ch) && um[toupper(ch)] != 0)
            answer += cont;
    }

    return answer;
}

int main() {
    string word = "aaAbcBC";
    cout << numberOfSpecialChars(word) << "\n";    

    return 0;
}