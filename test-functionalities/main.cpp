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
    if(solution.size() == nums.size()) {
        // for(int e: solution)
        //     cout<< e << " ";
        // cout<<"\n";
        ++cont;
    }

    for(int i = 0; i < nums.size(); ++i) {
        if(find(solution.begin(), solution.end(), nums[i]) == solution.end()) {
            solution.push_back(nums[i]);
            backtrack_2(nums, solution, cont);
            solution.pop_back();
        }
    }
}

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

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    // backtrack(0, 8, arr);
    vector<int> solution;
    int cont = 0;
    backtrack_2(arr, solution, cont);
    printf("%d", cont);

    return 0;
}