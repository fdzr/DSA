#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> phone = {{'0'},           {'0'},
                              {'a', 'b', 'c'}, {'d', 'e', 'f'},
                              {'g', 'h', 'i'}, {'j', 'k', 'l'},
                              {'m', 'n', 'o'}, {'p', 'q', 'r', 's'},
                              {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};

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
            createCombination(i + 1, letters, result, res, k);
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
    string digit = "9";
    string res;

    // backtrack(0, {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}}, res);

    auto combinations = letterCombinations(digit);

    for (const auto &elem : combinations) cout << elem << "\n";

    return 0;
}