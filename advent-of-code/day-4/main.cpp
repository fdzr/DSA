#include <bits/stdc++.h>

using namespace std;

using um_ii = unordered_map<int, int>;
um_ii getNumbers(string numbers) {
    um_ii ans;
    stringstream ss(numbers);
    int number;
    while(ss>>number) {
        ans.insert(make_pair(number, 1));
    }

    return ans;
}

vector<int> getCommonCards(const um_ii &a, const um_ii &b) {
    vector<int> ans;

    for(const auto &[k, v]: b) {
        if(a.count(k) == 1)
            ans.push_back(k);
    }

    return ans;
}

int getPoints(const um_ii &a, const um_ii &b) {
    vector<int> ans = getCommonCards(a, b);

    return (ans.size() == 1)? 1 : pow(2, ans.size() - 1);
}

vector<pair<um_ii, um_ii>> parseInput(fstream &inputFile) {
    string line;
    vector<pair<um_ii, um_ii>> lottery;

    while(getline(inputFile, line)) {
        string numbers = line.substr(line.find(':') + 1);
        string winningNumbers = numbers.substr(0, numbers.find('|'));
        string givenNumbers = numbers.substr(numbers.find('|') + 1);

        um_ii wNumbers = getNumbers(winningNumbers);
        um_ii gNumbers = getNumbers(givenNumbers);
        lottery.push_back(make_pair(wNumbers, gNumbers));
    }

    return lottery;
} 

void check() {
    string line = "Card  10: 31 42 65  9 19 90 40 60 29 67 | 71 53 89 11  9 21 90  7 97 29 93 51 28 24 98 52 61 65 67 77 19 43 94 42 26";

    string numbers = line.substr(line.find(':') + 1);
    string winningNumbers = numbers.substr(0, numbers.find('|'));
    string givenNumbers = numbers.substr(numbers.find('|') + 1);
    
    auto wNumbers = getNumbers(winningNumbers);
    auto gNumbers = getNumbers(givenNumbers);
    cout<<getPoints(wNumbers, gNumbers);
}

int part1(fstream &inputFile) {
    int cont = 0;
    vector<pair<um_ii, um_ii>> ans = parseInput(inputFile);

    for(const auto &[a, b]: ans){
        cont += getPoints(a, b);
    }

    return cont;
}

void fillCopies(um_ii &copies, const int &index, const int &range, const int &times) {
    for(int j = 0; j < times; ++j)
        for(int i = index + 1; i <= range; ++i)
            copies[i]++;
}

int getScratchcards(fstream &inputFile){
    int cont = 0;
    int index = 1;
    um_ii copies;
    vector<pair<um_ii, um_ii>> ans = parseInput(inputFile);

    for(int i = 0; i < ans.size(); ++i)
        copies[i + 1] = 0;

    for(const auto &[a, b]: ans) {
        int commonCards = getCommonCards(a, b).size();
        fillCopies(copies, index, index + commonCards, 1 + copies[index]);
        ++index;
    }

    for(const auto & [ignore, values]: copies)
        cont += values + 1;


    return cont;
}

int part2(fstream & inputFile){
    return getScratchcards(inputFile);
}



int main(){
    fstream inputFile("input.txt");
    // cout<<part1(inputFile);
    cout<<part2(inputFile);


    return 0;
}