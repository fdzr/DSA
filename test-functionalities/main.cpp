#include <bits/stdc++.h>

using namespace std;

string ltrim(string cad)
{
    cad.erase(
        cad.begin(),
        find_if(cad.begin(), cad.end(), not_fn(::isspace)));

    return cad;
}

string rtrim(string cad)
{
    cad.erase(
        find_if(cad.rbegin(), cad.rend(), not_fn(::isspace)).base(),
        cad.end());

    return cad;
}

vector<string> split(string cad)
{
    vector<string> res;
    stringstream s(cad);
    string input;

    while (s >> input)
        res.push_back(input);

    return res;
}

struct Person
{
    int age;
    int height;
};

ostream &operator<<(ostream &out, const Person &p)
{
    out << "[" << p.age << "," << p.height << "]";
    return out;
}

void testVector()
{
    vector<int> v;
    v.reserve(100);

    // for(auto a: initializer_list<int>{1,2,3,4})
    //     v.push_back(a);

    for (auto e : v)
        cout << e << endl;
}

void testString()
{
    string s = "   this is a test   ";
    for (auto str : split(ltrim(rtrim(s))))
        cout << str << endl;
}

void testBitMasks()
{
    int x = 16;
    cout << (x & (x - 1));
}

int main()
{
    // auto s = std::chrono::high_resolution_clock::now();
    // for(int i = 0; i < 10000000; ++i){
    //     printf("%d\n", i);
    // }

    // auto e = std::chrono::high_resolution_clock::now();
    // auto d = std::chrono::duration_cast<std::chrono::seconds>(e - s);
    // printf("%ld\n", d.count());

    vector<int> v{1, 2};
    auto a = move(v);
    cout << a[0] << endl;
    cout << a[1] << endl;

    cout << (&v == nullptr) << endl;

    __builtin_popcount(128);

    return 0;
}