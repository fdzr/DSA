#include <bits/stdc++.h>

using namespace std;

int REDCUBES = 12;
int GREENCUBES = 13;
int BLUECUBES = 14;

int getNumber(string cad) {
    regex numberRegex(R"(\d+)");
    smatch match;

    regex_search(cad, match, numberRegex);

    return stoi(match.str());
}

string getColor(string cad){
    regex pattern(R"((red|green|blue))");
    smatch match;

    regex_search(cad, match, pattern);
    return match.str();

}

pair<int, vector<unordered_map<string, int>>> parseLine(string line){
    string game = line.substr(0, line.find(":"));
    string data = line.substr(line.find(":") + 1);

    stringstream ss(data);
    string chunks, part;
    vector<unordered_map<string, int>> samples;

    while(getline(ss, chunks, ';')) {
        stringstream parts(chunks);
        unordered_map<string, int> um;
        
        while(getline(parts, part, ','))
            um[getColor(part)] = getNumber(part);
        
        samples.push_back(um);
    }

    return {getNumber(game), samples};
}

bool isValidGame(vector<unordered_map<string, int>> samples) {
    for(auto sample: samples)
        if(sample["red"] > REDCUBES || sample["green"] > GREENCUBES || sample["blue"] > BLUECUBES)
            return false;    

    return true;
}

int part1(fstream &inputFile) {
    string line;
    int cont = 0;

    while(getline(inputFile,line)) {
        auto input = parseLine(line);
        if(isValidGame(input.second))
            cont += input.first;
    }

    return cont;
}

int getPower(vector<unordered_map<string, int>> samples) {
    int max_red = 0, max_green = 0, max_blue = 0; 

    for(auto sample: samples) {
        max_red = max(max_red, sample["red"]);
        max_green = max(max_green, sample["green"]);
        max_blue = max(max_blue, sample["blue"]);
    }

    return max_red * max_green * max_blue;
}

int part2(fstream &inputFile) {
    string line;
    int cont = 0;

    while(getline(inputFile, line)) {
        auto [ignore, samples] = parseLine(line);
        cont += getPower(samples);
    }

    return cont;
}   

int main() {
    fstream inputFile("input.txt");
    
    cout<<part2(inputFile);

    return 0;
}