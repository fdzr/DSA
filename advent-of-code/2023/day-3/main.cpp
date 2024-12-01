#include <bits/stdc++.h>

using namespace std;

void loadData(fstream &inputFile, vector<string> &engine) {
    string line;

    while(getline(inputFile, line))
        engine.push_back(line);
}

string findLeftNumber(int start, const string &line) {
    string number = "";
    string cad = line;
    int startAux;

    if(start - 1 >= 0 && isdigit(cad[start - 1])){
        startAux = start - 1;
        while(startAux >= 0 && isdigit(cad[startAux])) {
            number = cad[startAux--] + number;
        }
    }

    return number;
}

string findRightNumber(int end, const string &line) {
    string number = "";
    string cad = line;
    int endAux;

    if(end + 1 < cad.size() && isdigit(cad[end + 1])) {
        endAux = end + 1;
        while(endAux < cad.size() && isdigit(cad[endAux])) {
            number += cad[endAux++];
        }
    }

    return number;
}

int getGear(int start, int end, int row, const vector<string> &engine) {
    string numberLeft, numberRight;
    string numberLeftTop, numberRightTop;
    string numberLeftBottom, numberRightBottom;
    string cad = engine[row];
    vector<string> ans;

    numberLeft = findLeftNumber(start, cad);
    numberRight = findRightNumber(end, cad);
    if(!numberLeft.empty())
        ans.push_back(numberLeft);
    if(!numberRight.empty())
        ans.push_back(numberRight);

    if(row - 1 >= 0) {
        numberLeftTop = findLeftNumber(start, engine[row - 1]);
        numberRightTop = findRightNumber(end, engine[row - 1]);
        if(isdigit(engine[row - 1][start])) {
            if(!numberLeftTop.empty() && !numberRightTop.empty())
                ans.push_back((numberLeftTop + string(1, engine[row - 1][start]) + numberRightTop));
            else if(!numberLeftTop.empty())
                ans.push_back((numberLeftTop + string(1, engine[row - 1][start])));
            else if(!numberRightTop.empty())
                ans.push_back((string(1, engine[row - 1][start]) + numberRightTop));
            else if(numberLeftTop.empty() && numberRightTop.empty())
                ans.push_back(string(1, engine[row - 1][start]));

        }
        else if(!numberLeftTop.empty())
            ans.push_back(numberLeftTop);
        else if(!numberRightTop.empty())
            ans.push_back(numberRightTop);
    }

    if(row + 1 < engine.size()) {
        numberLeftBottom = findLeftNumber(start, engine[row + 1]);
        numberRightBottom = findRightNumber(end, engine[row + 1]);
        if(isdigit(engine[row + 1][start])) {
            if(!numberLeftBottom.empty() && !numberRightBottom.empty())
                ans.push_back((numberLeftBottom + string(1, engine[row + 1][start]) + numberRightBottom));
            else if(!numberLeftBottom.empty())
                ans.push_back((numberLeftBottom + string(1, engine[row + 1][start])));
            else if(!numberRightBottom.empty())
                ans.push_back((string(1, engine[row + 1][start]) + numberRightBottom));
            else if (numberLeftBottom.empty() && numberRightTop.empty())
                ans.push_back(string(1, engine[row + 1][start]));

        }
        else if(!numberLeftBottom.empty())
            ans.push_back(numberLeftBottom);
        else if(!numberRightBottom.empty())
            ans.push_back(numberRightBottom);
    }
    
    if(ans.size() == 2) {
        
        return stoi(ans[0]) * stoi(ans[1]);
    }

    assert(ans.size() <= 2);

    return 0;
}

long long getRatio(fstream &inputFile) {
    long long cont = 0;
    vector<string> engine;
    loadData(inputFile, engine);
    regex pattern(R"(\*)");

    for(int row = 0; row < engine.size(); ++row) {
        string cad = engine[row];
        int positions = 0;
        smatch match;

        for(;regex_search(cad, match, pattern);) {
            int startRange = match.position() + positions;
            int endRange = startRange + match.str().size() - 1;

            cont += getGear(startRange, endRange, row, engine);

            positions += match.prefix().length() + match.str().size();
            cad = match.suffix();
        }

    }

    return cont;
}

bool isValid(int start, int end, int row, const vector<string> &engine) {
    if(start - 1 >= 0 && engine[row][start - 1] != '.')
        return true;
    if(end + 1 < engine[row].size() && engine[row][end + 1] != '.')
        return true;
    if(row - 1 >= 0) {
        for(int i = max(start - 1, 0); i <= min(end + 1, int(engine[row - 1].size() - 1)); ++i){
            if(engine[row - 1][i] != '.' && !isdigit(engine[row - 1][i]))
                return true;
        }
    }
    if(row + 1 < engine.size()) {
        for(int i = max(start - 1, 0); i <= min(end + 1, int(engine[row + 1].size() - 1)); ++i){
            if(engine[row + 1][i] != '.' && !isdigit(engine[row + 1][i]))
                return true;
        }
    }

    return false;
}

int getValidSum(fstream &inputFile) {
    int cont = 0;
    vector<string> engine;
    loadData(inputFile, engine);
    regex pattern(R"(\d+)");

    string cad;
    int cantNumber = 0;
    int cantNumberValid = 0;

    for(int row = 0; row < engine.size(); ++row) {
        cad = engine[row];
        int positions = 0;
        smatch match;

        for(;regex_search(cad, match, pattern);) {
            int startRange = match.position() + positions;
            int endRange = startRange + match.str().size() - 1;
            cantNumber += 1;

            if(isValid(startRange, endRange, row, engine)) {
                cont += stoi(match.str());
                cantNumberValid += 1;
            }

            positions += match.prefix().length() + match.str().size();
            cad = match.suffix();
        }   
    }
    cout<<cantNumberValid<<"/"<<cantNumber<<endl;

    return cont;
}

int part1(fstream &inputFile) {
    return getValidSum(inputFile);
}

void check() {
    string cad = "....#.......425..............923.84*......947......999*..............*....280*345789..........732...&.....*.............14.............683.......";
    string cadAux = cad;
    smatch match;
    regex p(R"(\*)");
    int positions = 0;

    for(;regex_search(cadAux, match, p);) {
        int startRange = match.position() + positions;
        int endRange = startRange + match.str().size() - 1;
        
        string numberLeft = findLeftNumber(startRange, cad);
        string numberRight = findRightNumber(endRange, cad);
        cout<<numberLeft<<" "<<numberRight<<endl;
    
    
        
        positions += match.prefix().length() + match.str().size();
        cadAux = match.suffix();
    }
}

int main (){
    fstream inputFile{"input.txt"};
    // cout<<part1(inputFile);
    // check();
    cout<<getRatio(inputFile);
    

    return 0;
}