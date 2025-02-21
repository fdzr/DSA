#include <bits/stdc++.h>

using namespace std;

string ltrim(string cad) {
    cad.erase(cad.begin(), find_if(cad.begin(), cad.end(), not_fn(::isspace)));

    return cad;
}

string rtrim(string cad) {
    cad.erase(find_if(cad.rbegin(), cad.rend(), not_fn(::isspace)).base(), cad.end());

    return cad;
}

vector<string> split(string cad) {
    vector<string> res;
    stringstream s(cad);
    string input;

    while (s >> input) res.push_back(input);

    return res;
}

struct Person {
    int age;
    int height;
};

ostream &operator<<(ostream &out, const Person &p) {
    out << "[" << p.age << "," << p.height << "]";
    return out;
}

void testVector() {
    vector<int> v;
    v.reserve(100);

    // for(auto a: initializer_list<int>{1,2,3,4})
    //     v.push_back(a);

    for (auto e : v) cout << e << endl;
}

void testString() {
    string s = "   this is a test   ";
    for (auto str : split(ltrim(rtrim(s)))) cout << str << endl;
}

void testBitMasks() {
    int x = 16;
    cout << (x & (x - 1));
}

int find(int u, vector<int> &parent) {
    if (parent[u] == -1) return u;

    return parent[u] = find(parent[u], parent);
}

void backtrack(int start, int end, vector<int> arr) {
    if (start == arr.size()) {
        for (int e : arr) cout << e << " ";

        cout << "\n";

        return;
    }

    for (int i = start; i < end; ++i) {
        swap(arr[i], arr[start]);
        backtrack(start + 1, end, arr);
        swap(arr[i], arr[start]);
    }
}

void backtrack_2(vector<int> nums, vector<int> &solution, int &cont) {
    if (solution.size() == nums.size()) {
        // for(int e: solution)
        //     cout<< e << " ";
        // cout<<"\n";
        ++cont;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (find(solution.begin(), solution.end(), nums[i]) == solution.end()) {
            solution.push_back(nums[i]);
            backtrack_2(nums, solution, cont);
            solution.pop_back();
        }
    }
}

class Item {
   public:
    int a, b, c;
    Item(int _a, int _b, int _c) {
        a = _a;
        b = _b;
        c = _c;
    }
    bool operator<(const Item &other) const {
        if (a == other.a) {
            if (b == other.b) {
                return c < other.c;
            } else
                return b < other.b;
        }
        return a < other.a;
    }
};

class Compare {
   public:
    bool operator()(const pair<string, int> &a, const pair<string, int> &b) {
        if (a.second == b.second) return a.first > b.first;
        return a.second < b.second;
    }
};

int main() {
    // vector<int> v(10, -1);
    // v[9] = -1;

    // v[4] = 9;
    // v[5] = 9;
    // v[6] = 9;

    // v[0] = 4;
    // v[3] = 0;
    // v[1] = 3;
    // v[2] = 3;
    // v[7] = 6;
    // v[8] = 6;

    // cout<<find(3, v)<<"\n";

    // for(int i = 0; i < v.size(); ++i)
    //     cout<<i<<": "<<v[i]<<"\n";

    // set<pair<int, int>> s{{7, 2}, {1, 2}, {4, 3}};
    // for (auto elem : s)
    // {
    //     cout<<elem.first<<" "<<elem.second<<"\n";
    // }

    // vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    // // backtrack(0, 8, arr);
    // vector<int> solution;
    // int cont = 0;
    // backtrack_2(arr, solution, cont);
    // printf("%d", cont);

    // unordered_map<int, int> um = {{3,1}};

    // auto it = um.find(3);
    // cout<<it->first;

    // priority_queue<Item, vector<Item>, less<Item>> pq;
    // pq.push(Item(3, 2, 1));
    // pq.push(Item(3, 4, 1));
    // pq.push(Item(2, 4, 1));

    // while (!pq.empty()) {
    //     Item item = pq.top();
    //     pq.pop();
    //     cout << item.a << " " << item.b << " " << item.c << "\n";
    // }

    // vector<Item> v;
    // v.push_back(Item(3, 2, 1));
    // v.push_back(Item(3, 4, 1));
    // v.push_back(Item(2, 4, 1));

    // sort(v.begin(), v.end());

    // for (const auto &item : v) {
    //     cout << item.a << " " << item.b << " " << item.c << "\n";
    // }

    // vector<int> a = {1,5,4,3,6};
    // sort(a.begin(), a.end(), greater<int>());

    // for(const auto& e: a)
    //     cout<<e<<" ";

    // unordered_map<string, int> um;
    // string words[] = {"code",         "coder", "coding",   "codable",      "codec",
    //                   "codecs",       "coded", "codeless", "codec",        "codecs",
    //                   "codependence", "codex", "codify",   "codependents", "codes",
    //                   "code",         "coder", "codesign", "codec",        "codeveloper",
    //                   "codrive",      "codec", "codecs",   "codiscovered"};

    // for (const string &word : words) {
    //     um[word]++;
    // }

    // priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;
    // for (const auto &entry : um) {
    //     pq.push(entry);
    // }

    // while (pq.size() > 0) {
    //     auto item = pq.top();
    //     cout << item.first << " " << item.second << "\n";
    //     pq.pop();
    // }

    priority_queue<int> pq;
    for(int i = 1; i <= 10; ++i)
        pq.push(i);

    while(pq.size() > 1) {
        int e = pq.top();
        cout<< e << "\n";
        pq.pop();
    }

    return 0;
}