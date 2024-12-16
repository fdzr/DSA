#include <bits/stdc++.h>

using namespace std;

void createParenthesis(int open, int close, int n, string res, vector<string> &result) {
    if (res.size() == 2 * n) {
        result.push_back(res);
        return;
    }

    if (open < n) createParenthesis(open + 1, close, n, res + "(", result);

    if (close < open) createParenthesis(open, close + 1, n, res + ")", result);
}

vector<string> generateParenthesis(int n) {
    string res = "";
    vector<string> result;

    createParenthesis(0, 0, n, res, result);

    return result;
}

int main() {
    int n = 6;

    auto generatedStrings = generateParenthesis(n);

    for (const auto &e : generatedStrings) cout << e << "\n";

    return 0;
}