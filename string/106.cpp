#include <bits/stdc++.h>

// https://leetcode.com/problems/rearrange-words-in-a-sentence/description/

using namespace std;

vector<string> split(string text)
{
    stringstream format(text);
    string chunk;
    vector<string> ans;

    while (format >> chunk)
    {
        chunk[0] = tolower(chunk[0]);
        ans.push_back(chunk);
    }

    return ans;
}

string arrangeWords(string text)
{
    vector<pair<string, int>> chunkText;
    auto chunks = split(text);

    for (int i = 0; i < chunks.size(); ++i)
        chunkText.push_back({chunks[i], i});

    sort(chunkText.begin(), chunkText.end(), [](auto &a, auto &b)
         {
            if (a.first.size() < b.first.size())
                return true;
            if(a.first.size() == b.first.size())
                return a.second < b.second;

            return false;

        });

    string ans = "";
    for (int i = 0; i < chunkText.size() - 1; ++i)
    {
        if (i == 0)
            chunkText[0].first[0] = toupper(chunkText[0].first[0]);

        ans.append(chunkText[i].first + " ");
    }

    ans.append(chunkText[chunkText.size() - 1].first);

    return ans;
}

int main()
{
    string text = "Keep calm and code on";
    cout << arrangeWords(text);

    return 0;
}