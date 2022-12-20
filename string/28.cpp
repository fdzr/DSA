#include <bits/stdc++.h>

using namespace std;


vector<vector<string>> displayTable(vector<vector<string>>& orders) {
    unordered_map<string, int> um;
    set<string> foods;
    unordered_map<string, unordered_map<string, int>> tables;
    unordered_map<string, int> indexFood;
    vector<vector<string>> ans;
    vector<string> tmp;
    vector<pair<string, pair<string, string>>> aux;
    vector<int> indexTables;

    for(auto v: orders) {
       foods.insert(v[2]);
       tables[v[1]][v[2]]++;
    }

    transform(tables.begin(), tables.end(), back_inserter(indexTables), [](auto item){
        return stoi(item.first);
    });

    sort(indexTables.begin(), indexTables.end());

    int index = 1;
    for(auto f: foods)
        indexFood[f] = index++;
    
    for(auto food: foods)
        tmp.push_back(food);

    tmp.insert(tmp.begin(), "Table");
    ans.push_back(tmp);
    tmp.clear();


    for(auto indexTable: indexTables) {
        tmp.assign(foods.size() + 1, "0");
        tmp[0] = to_string(indexTable);
        for(auto food: tables[to_string(indexTable)]) {
            tmp[indexFood[food.first]] = to_string(food.second);
        }

        ans.push_back(tmp);
        tmp.clear();
    }

    return ans;
}


int main() {
    vector<vector<string>> orders = {{"David","3","Ceviche"},
                                     {"Corina","10","Beef Burrito"},
                                     {"David","3","Fried Chicken"},
                                     {"Carla","5","Water"},
                                     {"Carla","5","Ceviche"},
                                     {"Rous","3","Ceviche"}};
    displayTable(orders);
    

    return 0;
}