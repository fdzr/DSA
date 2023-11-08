#include <bits/stdc++.h>

using namespace std;

bool equalFrequency(string word)
{
    if (word.size() == 2 && word.at(0) == word.at(1))
        return true;

    vector<int> freq(26, 0);
    unordered_map<int, int> freqTable;
    int cantElemInserted = 0;

    for (auto ch : word)
        freq[ch - 97]++;

    for (auto elem : freq)
    {
        if (elem != 0)
        {
            ++cantElemInserted;
            freqTable[elem]++;
        }
    }
    if (freqTable.size() > 2)
        return false;
    if (freqTable.size() == 2)
    {
        if (any_of(freqTable.begin(), freqTable.end(), [](auto p)
                   { return p.first == 1 && p.second == 1; }))
                return true;

            bool isDiffOne = abs(freqTable.begin()->first - (++freqTable.begin())->first) == 1;
        auto [freqMax, cantFreqMax] = *max_element(freqTable.begin(), freqTable.end(), [](auto p1, auto p2)
                                                   { return p1.first < p2.first; });
        auto [freqMin, cantFreqMin] = *min_element(freqTable.begin(), freqTable.end(), [](auto p1, auto p2)
                                                   { return p1.first < p2.first; });

        if (isDiffOne && (cantFreqMax == 1 || (cantFreqMin == 1 && freqMin == 1)))
            return true;
        else
            return false;
    }

    if (freqTable.size() == 1)
    {
        if (freqTable.begin()->first != 1 && freqTable.begin()->second == 1)
            return true;

        if (freqTable.begin()->first == 1)
            return true;

        return false;
    }

    return false;
}

int main()
{
    string word = "cccd";
    cout << equalFrequency(word);

    return 0;
}