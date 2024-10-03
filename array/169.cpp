#include <bits/stdc++.h>

using namespace std;

int numDifferentIntegers(string word)
{
    string number;
    unordered_map<string, int> um;

    for (int i = 0; i < word.size(); ++i)
    {
        if (isdigit(word[i]))
            number.push_back(word[i]);
        else if (!number.empty())
        {
            int index = 0;
            while(number[index] == '0')
                ++index;

            um[number.substr(index)]++;
            number.clear();
        }
    }

    if (!number.empty()) {
        int index = 0;
        while(number[index] == '0')
            ++index;
        
        um[number.substr(index)]++;
        number.clear();

    }

    return um.size();
}

int main()
{
    string cad = "a1b01c001";
    cout << numDifferentIntegers(cad);

    return 0;
}