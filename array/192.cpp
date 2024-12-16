#include <bits/stdc++.h>

using namespace std;

bool isAdjacent(string a, string b) {
    if (a.size() != b.size()) return false;

    int cont = 0;
    for (int i = 0; i < a.size(); ++i)
        if (a[i] != b[i]) ++cont;

    return (cont > 1) ? false : true;
}

void BFS(string start, string target, unordered_map<string, int> &visited, int &cont,
         vector<string> &dictionary) {
    
    if (start == target) {
        return;
    }

    queue<pair<string, int>> q;
    q.push({start, 0});

    while (!q.empty()) {
        auto v = q.front();
        q.pop();

        if(v.first == target) {
            cont = min(cont, v.second);
            return;
        }

        visited[v.first] = 1;

        for (const auto &elem : dictionary) {
            if (visited[elem] == 0 && isAdjacent(v.first, elem)) {
                q.push({elem, v.second + 1});
            }
        }
    }
}

int main() {
    vector<string> dictionary = {"POON", "PLEE", "SAME", "POIE", "PLEA", "PLIE", "POIN"};
    string start = "TOON";
    string target = "PLEA";
    unordered_map<string, int> um;
    int cont = INT_MAX;

    for (int i = 0; i < dictionary.size(); ++i) um[dictionary[i]] = 0;

    BFS(start, target, um, cont, dictionary);

    cout << cont + 1<<"\n";

    dictionary.clear();
    dictionary = {"ABCD", "EBAD", "EBCD", "XYZA"};
    start = "ABCV";
    target = "EBAD";
    um.clear();
    cont = INT_MAX;

    for (int i = 0; i < dictionary.size(); ++i) um[dictionary[i]] = 0;

    BFS(start, target, um, cont, dictionary);

    cout << cont + 1<<"\n";

    return 0;
}