#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> phone = {{'0'},           {'0'},
                              {'a', 'b', 'c'}, {'d', 'e', 'f'},
                              {'g', 'h', 'i'}, {'j', 'k', 'l'},
                              {'m', 'n', 'o'}, {'p', 'q', 'r', 's'},
                              {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};

unordered_map<char, string> um = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                  {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                  {'8', "tuv"}, {'9', "wxyz"}};


void backtrack_2(int start, vector<string> &result, string &res, string digit){
    if(digit.size() == res.size()) {
        result.push_back(res);
        return;
    }

    string aux = um[digit[start]];
    for(int i = 0; i < aux.size(); ++i) {
        res += aux[i];
        backtrack_2(start + 1, result, res, digit);
        res.pop_back();
    }

}

vector<string> help(string digit) {
    if(digit.size() == 0)
        return {};

    string res;
    vector<string> result;

    backtrack_2(0, result, res, digit);

    return result;
}



void createCombination(int start, const vector<vector<char>> &letters,
                       vector<string> &result, string &res, int k) {
    if (k == res.size()) {
        result.push_back(res);
        return;
    }

    for (int i = start; i < letters.size(); ++i) {
        for (int j = 0; j < letters[i].size(); ++j) {
            if (res == "" && i != 0) continue;

            res.push_back(letters[i][j]);
            createCombination(start + 1, letters, result, res, k);
            res.pop_back();
        }
    }
}

vector<string> letterCombinations(string digits) {
    if (digits.size() == 0) return {};

    vector<vector<char>> lists;
    vector<string> result;
    string res;

    for (int i = 0; i < digits.size(); ++i) {
        lists.push_back(phone[digits[i] - '0']);
    }

    int k = lists.size();

    createCombination(0, lists, result, res, k);

    return result;
}

void backtrack(int start, const vector<vector<char>> &lists, string &result) {
    if (result.size() == lists.size()) {
        cout << result << "\n";
        return;
    }

    for (int i = start; i < lists.size(); ++i) {
        for (int j = 0; j < lists[i].size(); ++j) {
            if (result == "" && i != 0) continue;

            result.push_back(lists[i][j]);
            backtrack(start + 1, lists, result);
            result.pop_back();
        }
    }
}

int main() {
    string digit = "237";
    string res;

    // backtrack(0, {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}}, res);

    // auto combinations = letterCombinations(digit);
    auto combinations = help(digit);

    for (const auto &elem : combinations) cout << elem << "\n";

    return 0;
}