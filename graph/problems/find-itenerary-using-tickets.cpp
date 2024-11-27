#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

vector<string> iteneraries = {
    "Chennai -> Banglore",
    "Bombay -> Delhi",
    "Goa    -> Chennai",
    "Delhi  -> Goa",
};

vector<int> topologicalSorting(Graph &G, vector<int> &inDegree) {
    queue<int> q;
    vector<int> order;

    for (int i = 0; i < inDegree.size(); ++i)
        if (inDegree[i] == 0)
            q.push(i);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int i = 0; i < G[u].size(); ++i) {
            --inDegree[G[u][i]];

            if (inDegree[G[u][i]] == 0)
                q.push(G[u][i]);
        }
    }

    if (accumulate(inDegree.begin(), inDegree.end(), 0) != 0) {
        cout << "cycle detected ...";
        exit(0);
    }

    return order;
}

void addEdge(Graph &G, int src, int dest, vector<int> &inDegree) {
    G[src].push_back(dest);
    ++inDegree[dest];
}

void printItenerary(vector<int> order, unordered_map<int, string> um) {
    for (int i = 0; i < order.size(); ++i) {
        if (i != order.size() - 1)
            cout << um[order[i]] << " -> ";
        else
            cout << um[order[i]];
    }

    cout<<"\n";
}

vector<pair<string, string>> format() {
    vector<pair<string, string>> dest;
    pair<string, string> temp;

    for (const auto &elem : iteneraries) {
        int pos = elem.find("->");

        if (elem[pos - 1] == ' ')
            temp.first = elem.substr(0, pos - 1);
        else
            temp.first = elem.substr(0, pos);

        if (elem[pos + 2] == ' ')
            temp.second = elem.substr(pos + 3);
        else
            temp.second = elem.substr(pos + 2);

        string aux = temp.first;
        int pos_first_aux = aux.find_first_not_of(" ");
        int pos_last_aux = aux.find_last_not_of(" ");
        temp.first = aux.substr(pos_first_aux, pos_last_aux - pos_first_aux + 1);

        aux = temp.second;
        pos_first_aux = aux.find_first_not_of(" ");
        pos_last_aux = aux.find_last_not_of(" ");
        temp.second = aux.substr(pos_first_aux, pos_last_aux - pos_first_aux + 1);

        dest.push_back(temp);
    }

    return dest;
}

tuple<Graph, unordered_map<int, string>, vector<int>> createListAdj() {
    vector<pair<string, string>> tickets = format();
    unordered_set<string> us;
    unordered_map<int, string> index2station;
    unordered_map<string, int> station2index;

    for (const auto &item : tickets)
        us.insert(item.first), us.insert(item.second);

    int index = 0;
    Graph G(us.size());
    vector<int> inDegree(us.size());

    for (const auto &elem : us) {
        index2station[index] = elem;
        station2index[elem] = index;
        ++index;
    }

    for (const auto &ticket : tickets) {
        addEdge(G, station2index[ticket.first], station2index[ticket.second], inDegree);
    }

    return {G, index2station, inDegree};
}

int main() {
    auto [G, um, inDegree] = createListAdj();
    auto order = topologicalSorting(G, inDegree);
    printItenerary(order, um);

    return 0;
}