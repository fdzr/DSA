#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

vi convertToNumbers(const string &line) {
    vi ans;
    int number;
    stringstream ss(line);

    while(ss>>number)
        ans.push_back(number);

    return ans;
}

vector<vi> loadData(const string &name) {
    fstream input{name};
    string line;
    vector<vi> data;

    while(getline(input, line)) {
        data.push_back(convertToNumbers(line));
    }

    return data;
}

vi diff(const vi &num) {
    vi temp;
    temp.reserve(num.size() - 1);

    for(int i = 1; i < num.size(); ++i) {
        temp.push_back(num[i] - num[i - 1]);
    }

    return temp;
}

int extrapolate2part(vi num) {
    int diff = 0;

    int startNumber = num.back();

    for(int i = num.size() - 2; i >= 0; i-=1) {
        diff = num[i] - startNumber;
        startNumber = diff;
    }


    return diff;
}

int main (int argc, char *argv[]) {
    if(argc > 2 || argc == 1)
        cerr<<"missing argument"<<endl;

    int part1 = 0;
    int part2 = 0;
    for(auto v: loadData(string(argv[1]))) {
        vi startValue;
        startValue.push_back(v.front());

        part1 += v.back();
        vi res = diff(v);
        part1 += res.back();
        startValue.push_back(res.front());

        while(all_of(res.begin(), res.end(), [res](int x) { return x == res.back(); }) == false) {
            res = diff(res);
            part1 += res.back();
            startValue.push_back(res.front());
        }

        part2 += extrapolate2part(startValue);
    }

    cout<<part1<<endl;
    cout<<part2;

    return 0;
}