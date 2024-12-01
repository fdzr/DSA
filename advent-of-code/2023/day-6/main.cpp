#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vll = vector<long long int>;
using pvi = pair<vi, vi>;
using pvll = pair<vll, vll>;

vector<long long int> readNumbers(const string &cad, bool part2 = false) {
    stringstream ss(cad);
    int number;
    vector<long long int> res;

    while(ss>>number)
        res.push_back(number);

    if(part2) {
        string aux = "";

        for(auto e: res) {
            aux += to_string(e);
        }

        res.clear();
        res.push_back(stoll(aux));
    }
    

    return res;
}

pvll loadData(fstream &input, bool part2 = false) {
    string line;
    vector<long long int> time, distance;

    while(getline(input, line)) {
        string aux = line.substr(line.find(':') + 1);
        if(line.find("Time") != string::npos)
            time = readNumbers(aux, part2);
        else 
            distance = readNumbers(aux, part2);
    }

    return {time, distance};
}


long long int getWaysToWin(fstream &input, bool part2 = false) {
    long long int cont = 1;

    const auto &[time, distance] = loadData(input, part2);

    for(long long int i = 0 ; i < time.size(); ++i) {
        long long int ways = 0;
        for(long long int j = 1; j <= (time[i] / 2); ++j) {
            long long int dis = j * (time[i] - j);
            if(dis > distance[i]) {
                if(time[i] % 2 == 0 && time[i] / 2 == j)
                    ways += 1;
                else 
                    ways += 2;
            } 
        }
        cont *= ways;
    }
    
    return cont;
}

int part1(fstream &input) {
    return getWaysToWin(input);
}

long long int part2(fstream &input) {
    return getWaysToWin(input, true);
}

int main(){
    fstream input{"input.txt"};
    cout<<part2(input);

    return 0;
}