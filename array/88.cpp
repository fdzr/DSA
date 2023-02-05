#include <bits/stdc++.h>

using namespace std;

int calPoints(vector<string>& operations) {
    vector<int> scores;
    for(auto str: operations) {
        try {
            int number = stoi(str);
            scores.push_back(number);
        }
        catch(const std::exception& e) {
            if(str == "C")
                scores.pop_back();
            else if(str == "D")
                scores.push_back(scores.back() * 2);
            else if(str == "+") {
                auto ptr = scores.end() - 2;
                scores.push_back(*ptr + scores.back());
            }
        }
    }
    return accumulate(scores.begin(), scores.end(), 0);
}



int main() {
    vector<string> operations = {"1", "C"};
    cout<<calPoints(operations);


    return 0;
}