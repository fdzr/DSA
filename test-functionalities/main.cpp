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

int find(int u, vector<int> &parent)
{
    if(parent[u] == -1)
        return u;

    return parent[u] = find(parent[u], parent);
}

int main()
{
    vector<int> v(10, -1);
    v[9] = -1;

    v[4] = 9;
    v[5] = 9;
    v[6] = 9;

    v[0] = 4;
    v[3] = 0;
    v[1] = 3;
    v[2] = 3;
    v[7] = 6;
    v[8] = 6;

    cout<<find(3, v)<<"\n";

    for(int i = 0; i < v.size(); ++i)
        cout<<i<<": "<<v[i]<<"\n";



    return 0;
}