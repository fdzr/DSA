#include <bits/stdc++.h>

using namespace std;

vector<string> code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};


int uniqueMorseRepresentations(vector<string>& words) {
    unordered_set<string> answer;
    string cad = "";

    for(auto word: words) {
        for(auto ch: word) {
            cad += code[ch - 97];
        }
        
        answer.insert(cad);
        cad = "";
    }

    return answer.size();
}

int main() {
    vector<string> input = {"gin","zen","gig","msg"};
    cout<<uniqueMorseRepresentations(input);

    return 0;
}