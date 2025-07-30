#include <bits/stdc++.h>

#include "../common/tree.h"

using namespace std;
using namespace Tree;

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

void setItem(Item *item) {
    item->a = 10;
    item->b = 11;
    item->c = 12;
}

class Test {
    int a;

   public:
    int getA() const { return a; }
    void setA(int v) { a = v; }
    Test(int _a) : a{_a} {}
    Test() : a{0} {}
    Test(const Test &other) {
        cout << "calling the copy constructor ..." << "\n";
        a = other.a;
    }
    Test &operator=(const Test &other) {
        cout << "calling the assignation operator ..." << "\n";
        this->setA(other.getA());
        return *this;
    }
};

template <typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> convertible_to<T>;
};

template <typename T>
// requires Addable<T>
T add(T a, T b) {
    static_assert(Addable<T>, "Type must support addition");
    return a + b;
}

void changeValueFromNode(TreeNode<int> *root, int value) { root->left->val = value; }
void removeNode(TreeNode<int> *&root) {
    delete root;
    root = nullptr;
}

int main() {
    auto t0 = chrono::system_clock::now();
    this_thread::sleep_for(1s);
    auto t1 = chrono::system_clock::now();
    cout << duration_cast<chrono::seconds>(t1 - t0).count();
    cout << "\n";

    cout<< ("azass" > "zb");

    return 0;
}