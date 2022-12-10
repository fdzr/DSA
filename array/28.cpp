#include <bits/stdc++.h>

using namespace std;


int aux(vector<string> item, string ruleKey, string ruleValue) {
    if(ruleKey == "type" && ruleValue == item[0])
        return 1;
    if(ruleKey == "color" && ruleValue == item[1])
        return 1;
    if(ruleKey == "name" && ruleValue == item[2])
        return 1;

    return 0;
}

int countMatches(
    vector<vector<string>>& items, 
    string ruleKey, 
    string ruleValue) {
    int cont = 0;
    for(auto item: items)
        cont += aux(item, ruleKey, ruleValue);

    return cont;
        
}


int main() {
    vector<vector<string>> items = {{"phone","blue","pixel"},
                                    {"computer","silver","lenovo"},
                                    {"phone","gold","iphone"}};
    string ruleKey = "color";
    string ruleValue = "silver";
    cout<<countMatches(items, ruleKey, ruleValue);

    return 0;
}